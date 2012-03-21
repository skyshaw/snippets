#include <iostream>

template <class S, class T>
class Foo {
public:
	Foo() {
		std::cout << "master" << std::endl;
	}
};

template <class T>
class Foo<int, T> {
public:
	Foo() {
		std::cout << "partial" << std::endl;
	}
};

template <>
class Foo<int, int> {
public:
	Foo() {
		std::cout << "total" << std::endl;
	}
};

int main(int argc, char** argv) {
	Foo<double, double> foo1;
	Foo<int, double> foo2;
	Foo<int, int> foo3;
	return 0;
}