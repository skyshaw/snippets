#include <iostream>
#include <boost/function.hpp>
#include <boost/bind.hpp>

using namespace std;
using namespace boost;

int foo(int a, int b) {
  return a + b;
}

struct bar {
  int add(int a, int b) {
    return a + b;
  }
  int operator()(int x) const {
    return x * x;
  }
}; 

int main() {
  function<int(int, int)> func;
  assert(!func);
  func = foo;
  if (func) {
    cout << func(10, 20) << endl;
  }
  func = 0;
  assert(func.empty());

  function<int(bar&, int, int)> func1;
  func1 = bind(&bar::add, _1, _2, _3);
  bar b;
  cout << func1(b, 1, 2) << endl;
  function<int(int, int)> func2;
  func2 = bind(&bar::add, &b, _1, _2);
  cout << func2(1, 2) << endl;

  return 0;
}
