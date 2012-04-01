#include <iostream>
#include <cmath>
#include <typeinfo>
#include <boost/utility/result_of.hpp>

using namespace std;
using namespace boost;

template <typename T, typename T1>
typename result_of<T(T1)>::type call_func(T t, T1 t1) {
  return t(t1);
}

int main() {
  typedef double (*Func)(double d);
  Func func = sqrt;
  //result_of<Func(double)>::type x = func(5.0);
  auto x = call_func(func, 0.5);
  cout << typeid(x).name() << endl;
  return 0;
}
