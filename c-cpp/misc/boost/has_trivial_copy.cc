#include <iostream>
#include <boost/type_traits.hpp>

using namespace std;

class Foo {
 private:
  int member;
};

class Bar {
 public:
  Bar() {
  }
  Bar(const Bar& other) {
    //pretend to be not rivial
  }
 private:
  int member;
};

template <typename T>
typename std::enable_if<
  !boost::has_trivial_copy<T>::value
>::type
func(T) {
  cout << "no trivial copy" << endl;
}

template <typename T>
typename std::enable_if<
  boost::has_trivial_copy<T>::value
>::type
func(T) {
  cout << "has trivial copy" << endl;
}

int main() {
  func(Foo());
  func(Bar());
  return 0;
}
