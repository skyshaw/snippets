#include <iostream>
#include <iterator>
#include <algorithm>
#include <functional>
#include <vector>
#include <deque>
#include "algostuff.hpp"

using namespace std;

int main() {
  deque<int> coll;
  vector<int> coll1(6);
  vector<int> coll2(30);
  INSERT_ELEMENTS(coll, 3, 7);
  INSERT_ELEMENTS(coll, 2, 6);
  INSERT_ELEMENTS(coll, 1, 5);
  PRINT_ELEMENTS(coll);
  vector<int>::iterator pos;
  pos = partial_sort_copy(coll.begin(), coll.end(),
                          coll1.begin(), coll1.end());
  copy(coll1.begin(), pos,
       ostream_iterator<int>(cout, " "));
  cout << endl;

  pos = partial_sort_copy(coll.begin(), coll.end(),
                          coll2.begin(), coll2.end(),
                          greater<int>());
  copy(coll2.begin(), pos,
       ostream_iterator<int>(cout, " "));
  cout << endl;
  return 0;
}
