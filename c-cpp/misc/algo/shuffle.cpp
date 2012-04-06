#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include "algostuff.hpp"

using namespace std;

class MyRandom {
 public:
  ptrdiff_t operator()(ptrdiff_t max) {
    double tmp = static_cast<double>(rand()) /
        static_cast<double>(RAND_MAX);
    return static_cast<ptrdiff_t>(tmp * max);
  }

};

int main() {
  vector<int> coll;
  INSERT_ELEMENTS(coll, 1, 9);
  PRINT_ELEMENTS(coll);

  random_shuffle(coll.begin(), coll.end());
  PRINT_ELEMENTS(coll);

  sort(coll.begin(), coll.end());
  MyRandom rd;
  random_shuffle(coll.begin(), coll.end(), rd);
  PRINT_ELEMENTS(coll);

  return 0;
}
