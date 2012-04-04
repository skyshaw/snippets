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
  reverse(coll.begin(), coll.end());
  PRINT_ELEMENTS(coll);
  reverse(coll.begin() + 1, coll.end() - 1);
  PRINT_ELEMENTS(coll);
  reverse_copy(coll.begin(), coll.end(),
               ostream_iterator<int>(cout, " "));
  cout << endl;
  return 0;
}
