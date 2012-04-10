#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include "algostuff.hpp"

using namespace std;

int main() {
  vector<int> coll;
  INSERT_ELEMENTS(coll, 3, 7);
  INSERT_ELEMENTS(coll, 2, 6);
  INSERT_ELEMENTS(coll, 1, 5);
  partial_sort(coll.begin(), coll.begin() + 5, coll.end());
  PRINT_ELEMENTS(coll);

  partial_sort(coll.begin(), coll.begin() + 5, coll.end(),
               greater<int>());
  PRINT_ELEMENTS(coll);
  partial_sort(coll.begin(), coll.end(), coll.end());
  PRINT_ELEMENTS(coll);
  return 0;
}
