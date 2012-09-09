#include <atomic>
#include <thread>
#include <string>
#include <iostream>
#include <mutex>
#include <chrono>
#include <cstdlib>

//FIXME: memory leak
template <class T>
class LockFreeQueue {
public:
	struct Node {
		Node(T const& val = T()): next(nullptr), value(val) {
		}
		std::atomic<Node*> next;
		T value;
	};

	LockFreeQueue(): head(new Node) {
		tail.store(head);
	}
	void enqueue(T const& x) {
		std::atomic<Node*>  q(new Node(x));
		q.load()->next = nullptr;
		std::atomic<Node*>  p = nullptr;
		Node* dummy = nullptr;
		for (;;) {
			dummy = nullptr;
			p.store(tail.load());
			if (std::atomic_compare_exchange_weak(&(p.load()->next), &dummy, q.load())) {
				break;
			} else {
				dummy = p.load();
				std::atomic_compare_exchange_weak(&tail, &dummy, p.load()->next.load());
			}
		}
		dummy = p.load();
		std::atomic_compare_exchange_weak(&tail, &dummy, q.load());
	}
	T dequeue() {
		std::atomic<Node*> p = nullptr;
		for (;;) {
			p.store(head.load());
			if (!(p.load()->next.load())) {
				throw std::string("queue empty");
			}
			Node* dummy = p.load();
			if (std::atomic_compare_exchange_weak(&head, &dummy, p.load()->next.load())) {
				break;
			}
		}
		return p.load()->next.load()->value;
	}
	int count() {
		int result = 0;
		for (Node* p = head.load(); p != tail.load(); p = p->next.load()) {
			++result;
		}
		return result;
	}
private:
	std::atomic<Node*>  head, tail;
};



template <class T>
class MutexQueue {
public:
	struct Node {
		Node(T const& val = T()): next(nullptr), value(val) {
		}
		Node* next;
		T value;
	};

	MutexQueue(): head(new Node) {
		tail = head;
	}
	void enqueue(T const& x) {
		std::lock_guard<std::mutex> lg(queue_mutex);
		Node* p(new Node(x));
		tail->next = p;
		tail = p;
	}
	T dequeue() {
		std::lock_guard<std::mutex> lg(queue_mutex);
		if (!head->next) {
			throw std::string("queue empty");
		}
		head = head->next;
		return head->value;
	}
	int count() {
		int result = 0;
		for (Node* p = head; p != tail; p = p->next) {
			++result;
		}
		return result;
	}
private:
	Node *head, *tail;
	std::mutex queue_mutex;
};


template <class T>
void func(T* Q, std::atomic<int>* count) {
	const int num = 400;
	for (int i = 0; i < num; ++i) {
		if (i % 3 == 2) {
			try {
				int v = Q->dequeue();
				(*count)--;
			} catch(...) {
				
			}
		} else {
			Q->enqueue(i);
			(*count)++;
		}
	}
}

int main() {
	const int num_threads = 100;
	std::thread threads[num_threads];

	const int num_iter = 10;
	std::atomic<int> count;
	std::chrono::milliseconds total(0);

	for (int iter = 0; iter < num_iter; ++iter) {
		LockFreeQueue<int> Q1;
		count = 0;
		auto start = std::chrono::system_clock::now();
		for (int i = 0; i < num_threads; ++i) {
			threads[i] = std::thread(func<LockFreeQueue<int>>, &Q1, &count);
		}
		for (int i = 0; i < num_threads; ++i) {
			threads[i].join();
		}
		auto diff = std::chrono::system_clock::now() - start;
		std::cout << count << " " << Q1.count() << " " << diff.count() << std::endl;
		total += std::chrono::duration_cast<std::chrono::milliseconds>(diff);
	}
	std::cout << "avg = " << total.count() / num_iter << std::endl;
	
	total.zero();

	for (int iter = 0; iter < num_iter; ++iter) {
		MutexQueue<int> Q2;
		count = 0;
		auto start = std::chrono::system_clock::now();
		for (int i = 0; i < num_threads; ++i) {
			threads[i] = std::thread(func<MutexQueue<int>>, &Q2, &count);
		}
		for (int i = 0; i < num_threads; ++i) {
			threads[i].join();
		}
		auto diff = std::chrono::system_clock::now() - start;
		std::cout << count << " " << Q2.count() << " " << diff.count() << std::endl;
		total += std::chrono::duration_cast<std::chrono::milliseconds>(diff);
	}
	std::cout << "avg = " << total.count() / num_iter << std::endl;
	system("pause");
	return 0;
}