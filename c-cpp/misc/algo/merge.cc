#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include "algostuff.hpp"

using namespace std;

int main() {
  vector<int> coll1;
  vector<int> coll2; 
  INSERT_ELEMENTS(coll1, 1, 6);
  INSERT_ELEMENTS(coll2, 3, 8);
  PRINT_ELEMENTS(coll1);
  PRINT_ELEMENTS(coll2);
  merge(coll1.begin(), coll1.end(),
        coll2.begin(), coll2.end(),
        ostream_iterator<int>(cout, " "));
  cout << endl;
  return 0;
}
