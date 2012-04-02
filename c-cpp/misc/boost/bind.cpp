#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <boost/bind.hpp>
#include <utility>
#include <functional>
#include <string>


using namespace std;
using namespace boost;

int f(int a, int b) {
  return a + b;
}

int g(int a, int b, int c) {
  return a + b * c;
}

typedef int (*f_type)(int, int);
typedef int (*g_type)(int, int, int);

struct demo {
  int f(int a, int b) {
    return a + b;
  }
};

struct point {
  point(int a = 0, int b = 0) : x(a), y(b) {
  }
  void print() {
    cout << '(' << x << ',' << y << ')' << endl;
  }
  int x, y;
};

int main() {
  cout << bind(f, 1, 2)() << endl;
  cout << bind(g, 1, 2, 3)() << endl;
  f_type pf = f;
  g_type pg = g;
  int x = 1, y = 2, z = 3;
  cout << bind(pf, _1, 9)(x) << endl;
  cout << bind(pg, _3, _2, _2)(x, y, z) << endl;

  demo a, &ref_a = a;
  demo *ptr_a = &a;
  cout << bind(&demo::f, a, _1, 9)(x) << endl;
  cout << bind(&demo::f, ref_a, _1, _2)(x, y) << endl;
  cout << bind(&demo::f, ptr_a, _2, _1)(x, y) << endl;
  cout << bind(&demo::f, _1, _2, _3)(a, x, y) << endl;

  vector<point> v(10);
  for_each(v.begin(), v.end(), bind(&point::print, _1));

  vector<int> v2(10);
  transform(v.begin(), v.end(), ostream_iterator<int>(cout, " "),
            bind(&point::x, _1));
  cout << endl;

  typedef pair<int, string> pair_t;
  pair_t p(123, "string");
  cout << bind(&pair_t::first, p)() << endl;
  cout << bind(&pair_t::second, p)() << endl;

  cout << bind(greater<int>(), _1, _2)(x, y) << endl;
  cout << bind(plus<int>(), _1, _2)(x, y) << endl;
  cout << bind(modulus<int>(), _1, _2)(x, y) << endl;

  return 0;
}
