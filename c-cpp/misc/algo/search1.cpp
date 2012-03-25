#include <iostream>
#include <deque>
#include <algorithm>
#include "algostuff.hpp"

using namespace std;

int main() {
  deque<int> coll;
  INSERT_ELEMENTS(coll, 1, 7);
  INSERT_ELEMENTS(coll, 1, 7);
  PRINT_ELEMENTS(coll);
  deque<int> subcoll;
  INSERT_ELEMENTS(subcoll, 3, 6);
  PRINT_ELEMENTS(subcoll);
  deque<int>::iterator pos;
  pos = search(coll.begin(), coll.end(), subcoll.begin(), subcoll.end());
  while (pos != coll.end()) {
    cout << distance(coll.begin(), pos) + 1 << endl;
    pos = search(++pos, coll.end(), subcoll.begin(), subcoll.end());
  }
  return 0;
}
