#include <iostream>
#include <algorithm>
#include <functional>
#include <iterator>
#include <deque>
#include <numeric>
#include "algostuff.hpp"

using namespace std;

int main() {
  deque<int> coll;
  INSERT_ELEMENTS(coll, 1, 6);
  PRINT_ELEMENTS(coll);
  adjacent_difference(coll.begin(), coll.end(),
                      ostream_iterator<int>(cout, " "));
  cout << endl;
  adjacent_difference(coll.begin(), coll.end(),
                      ostream_iterator<int>(cout, " "),
                      plus<int>());
  cout << endl;
  adjacent_difference(coll.begin(), coll.end(),
                      ostream_iterator<int>(cout, " "),
                      multiplies<int>());
  cout << endl;
  return 0;
}
