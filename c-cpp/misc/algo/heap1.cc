#include <iostream>
#include <algorithm>
#include <vector>
#include "algostuff.hpp"

using namespace std;

int main() {
  vector<int> coll;
  INSERT_ELEMENTS(coll, 3, 7);
  INSERT_ELEMENTS(coll, 5, 9);
  INSERT_ELEMENTS(coll, 1, 4);
  PRINT_ELEMENTS(coll);
  make_heap(coll.begin(), coll.end());
  PRINT_ELEMENTS(coll);
  pop_heap(coll.begin(), coll.end());
  coll.pop_back();
  PRINT_ELEMENTS(coll);
  coll.push_back(17);
  push_heap(coll.begin(), coll.end());
  PRINT_ELEMENTS(coll);
  sort_heap(coll.begin(), coll.end());
  PRINT_ELEMENTS(coll);
  return 0;
}
