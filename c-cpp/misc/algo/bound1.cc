#include <iostream>
#include <algorithm>
#include <vector>
#include "algostuff.hpp"

using namespace std;

int main() {
  vector<int> coll;
  INSERT_ELEMENTS(coll, 1, 9);
  INSERT_ELEMENTS(coll, 1, 9);
  sort(coll.begin(), coll.end());
  vector<int>::iterator pos;
  pos = lower_bound(coll.begin(), coll.end(), 5);
  cout << distance(coll.begin(), pos) + 1 << endl;
  pos = upper_bound(coll.begin(), coll.end(), 5);
  cout << distance(coll.begin(), pos) + 1 << endl;
  coll.insert(lower_bound(coll.begin(), coll.end(), 3), 3);
  coll.insert(upper_bound(coll.begin(), coll.end(), 7), 7);
  PRINT_ELEMENTS(coll);
  return 0;
}
