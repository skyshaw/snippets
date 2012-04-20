#include <iostream>
#include <algorithm>
#include <vector>
#include "algostuff.hpp"

using namespace std;

int main() {
  vector<int> coll;
  INSERT_ELEMENTS(coll, 1, 7);
  INSERT_ELEMENTS(coll, 1, 8);
  PRINT_ELEMENTS(coll);
  vector<int>::iterator pos;
  pos = find(coll.begin(), coll.end(), 7);
  inplace_merge(coll.begin(), ++pos, coll.end());
  PRINT_ELEMENTS(coll);
  return 0;
}
