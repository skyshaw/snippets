#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <numeric>
#include "algostuff.hpp"

using namespace std;

int main() {
  vector<int> coll;
  INSERT_ELEMENTS(coll, 1, 6);
  PRINT_ELEMENTS(coll);
  partial_sum(coll.begin(), coll.end(),
              ostream_iterator<int>(cout, " "));
  cout << endl;
  partial_sum(coll.begin(), coll.end(),
              ostream_iterator<int>(cout, " "),
              multiplies<int>());
  cout << endl;
  return 0;
}
