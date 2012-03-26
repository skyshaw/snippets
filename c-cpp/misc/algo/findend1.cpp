#include <iostream>
#include <algorithm>
#include <deque>
#include "algostuff.hpp"

using namespace std;

int main() {
  deque<int> coll;
  INSERT_ELEMENTS(coll, 1, 7);
  INSERT_ELEMENTS(coll, 1, 7);
  deque<int> subcoll;
  INSERT_ELEMENTS(subcoll, 3, 6);
  PRINT_ELEMENTS(coll);
  PRINT_ELEMENTS(subcoll);
  deque<int>::iterator pos;
  pos = find_end(coll.begin(), coll.end(),
                 subcoll.begin(), subcoll.end());
  deque<int>::iterator end(coll.end());
  while (pos != end) {
    cout << distance(coll.begin(), pos) + 1 << endl;
    end = pos;
    pos = find_end(coll.begin(), end,
                   subcoll.begin(), subcoll.end());
  }
  return 0;
}
