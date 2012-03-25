#include <iostream>
#include <algorithm>
#include <deque>
#include "algostuff.hpp"

using namespace std;

int main() {
  deque<int> coll;
  INSERT_ELEMENTS(coll, 1, 9);
  PRINT_ELEMENTS(coll);
  deque<int>::iterator pos;
  pos = search_n(coll.begin(), coll.end(), 4, 3);
  if (pos != coll.end()) {
    cout << "four consecutive 4 elements with 3 start with the " << 
        distance(coll.begin(), pos) + 1 << ".th elements\n";
  } else {
    cout << "no four consecutive elements with 3 found\n";
  }
  pos = search_n(coll.begin(), coll.end(), 4, 3, greater<int>());
  if (pos != coll.end()) {
    cout << "four consecutive 4 elements greater than 3 start with the " << 
        distance(coll.begin(), pos) + 1 << ".th elements\n";
  } else {
    cout << "no four consecutive elements greaer than 3 found\n";
  }
  return 0;
}
