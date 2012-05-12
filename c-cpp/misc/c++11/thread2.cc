#include <iostream>
#include <thread>

void foo(int tid) {
  std::cout << "Launched by thread " << tid << std::endl;
}
int main() {
  const int num_threads = 10;
  std::thread t[num_threads];
  for (int i = 0; i < num_threads; ++i) {
    t[i] = std::thread(foo, i);
  }
  std::cout << "Launched from the main" << std::endl;
  for (int i = 0; i < num_threads; ++i) {
    t[i].join();
  }
  return 0;
}
