#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include "algostuff.hpp"

using namespace std;

int main() {
  vector<int> coll;
  INSERT_ELEMENTS(coll, 1, 9);
  PRINT_ELEMENTS(coll);
  rotate(coll.begin(), coll.begin() + 1, coll.end());
  PRINT_ELEMENTS(coll);
  rotate(coll.begin(), coll.end() - 2, coll.end());
  PRINT_ELEMENTS(coll);
  rotate(coll.begin(), find(coll.begin(), coll.end(), 4),
         coll.end());
  PRINT_ELEMENTS(coll);
  return 0;
}
