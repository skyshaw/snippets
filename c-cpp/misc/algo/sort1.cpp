#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include "algostuff.hpp"

using namespace std;

int main() {
  vector<int> coll;
  INSERT_ELEMENTS(coll, 1, 9);
  INSERT_ELEMENTS(coll, 1, 9);

  sort(coll.begin(), coll.end());
  PRINT_ELEMENTS(coll);

  sort(coll.begin(), coll.end(),
       greater<int>());
  PRINT_ELEMENTS(coll);
  return 0;
}
