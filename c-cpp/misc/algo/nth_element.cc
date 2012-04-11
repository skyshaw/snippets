#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <iterator>
#include "algostuff.hpp"

using namespace std;

int main() {
  vector<int> coll;
  INSERT_ELEMENTS(coll, 3, 7);
  INSERT_ELEMENTS(coll, 2, 6);
  INSERT_ELEMENTS(coll, 1, 5);
  nth_element(coll.begin(), coll.begin() + 4, coll.end());
  copy(coll.begin(), coll.begin() + 4,
       ostream_iterator<int>(cout, " "));
  cout << endl;
  nth_element(coll.begin(), coll.end() - 4, coll.end());
  copy(coll.end() - 4, coll.end(),
       ostream_iterator<int>(cout, " "));
  cout << endl;
  nth_element(coll.begin(), coll.begin() + 3, coll.end(),
              greater<int>());
  copy(coll.begin(), coll.begin() + 4,
       ostream_iterator<int>(cout, " "));
  cout << endl;
  return 0;
}
