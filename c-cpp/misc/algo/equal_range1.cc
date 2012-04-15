#include <iostream>
#include <algorithm>
#include <list>
#include <utility>
#include "algostuff.hpp"

using namespace std;

int main() {
  list<int> coll;
  INSERT_ELEMENTS(coll, 1, 9);
  INSERT_ELEMENTS(coll, 1, 9);
  coll.sort();
  PRINT_ELEMENTS(coll);
  pair<list<int>::iterator, list<int>::iterator> pos;
  pos = equal_range(coll.begin(), coll.end(), 5);
  cout << distance(coll.begin(), pos.first) + 1 << endl;
  cout << distance(coll.begin(), pos.second) + 1 << endl;
  return 0;
}
