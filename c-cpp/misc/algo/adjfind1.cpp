#include <iostream>
#include <vector>
#include <algorithm>
#include "algostuff.hpp"

using namespace std;

bool Double(const int& lhs, const int& rhs) {
  return lhs * 2 == rhs;
}

int main() {
  vector<int> coll;
  coll.push_back(1);
  coll.push_back(3);
  coll.push_back(2);
  coll.push_back(4);
  coll.push_back(5);
  coll.push_back(5);
  coll.push_back(0);
  PRINT_ELEMENTS(coll);
  vector<int>::iterator pos;
  pos = adjacent_find(coll.begin(), coll.end());
  cout << distance(coll.begin(), pos) + 1 << endl;
  pos = adjacent_find(coll.begin(), coll.end(), Double);
  cout << distance(coll.begin(), pos) + 1 << endl;
  return 0;
}
