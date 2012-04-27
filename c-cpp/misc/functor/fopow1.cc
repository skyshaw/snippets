#include <iostream>
#include <algorithm>
#include <cmath>
#include <functional>
#include <vector>
#include <iterator>
#include "algostuff.hpp"

using namespace std;

template <typename T1, typename T2>
struct fopow: std::binary_function<T1, T2, T1> {
  T1 operator() (T1 base, T2 exp) const {
    return pow(base, exp);
  }
};

int main() {
  vector<int> coll;
  INSERT_ELEMENTS(coll, 1, 9);
  PRINT_ELEMENTS(coll);
  transform(coll.begin(), coll.end(),
            ostream_iterator<int>(cout, " "),
            bind1st(fopow<double, int>(), 3));
  cout << endl;
  transform(coll.begin(), coll.end(),
            ostream_iterator<int>(cout, " "),
            bind2nd(fopow<double, int>(), 3));
  cout << endl; 
  return 0;
}
