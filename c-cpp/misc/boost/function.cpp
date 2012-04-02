#include <iostream>
#include <vector>
#include <functional>
#include <boost/function.hpp>
#include <boost/bind.hpp>
#include <boost/ref.hpp>

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

template <typename T>
struct summary {
  typedef void result_type;
  summary(T v = T()) : sum(v) {
  }
  void operator()(T const& x) {
    sum += x;
  }
  T sum;
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

  function<int(int)> func3;
  func3 = cref(b);
  cout << func3(5) << endl;

  summary<int> s;
  int arr[] = {1, 2, 3, 4, 5};
  vector<int> coll(arr, arr + sizeof(arr) / sizeof(arr[0]));
  function<void(int const&)> func4(ref(s));
  for_each(coll.begin(), coll.end(), func4);
  cout << s.sum << endl;
  return 0;
}
