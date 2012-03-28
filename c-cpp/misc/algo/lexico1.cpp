#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include "algostuff.hpp"

using namespace std;

void printCollection(const list<int>& li) {
  PRINT_ELEMENTS(li);
}

bool LessForCollection(const list<int>& lhs, const list<int>& rhs) {
  return lexicographical_compare(lhs.begin(), lhs.end(),
                                 rhs.begin(), rhs.end());
}

int main() {
  list<int> li1, li2, li3, li4;
  INSERT_ELEMENTS(li1, 1, 5);
  li2 = li3 = li4 = li1;
  li2.push_back(2);
  li3.push_back(0);
  li4.push_back(1);
  vector<list<int> > coll;
  coll.push_back(li1);
  coll.push_back(li2);
  coll.push_back(li3);
  coll.push_back(li4);
  coll.push_back(li2);
  coll.push_back(li1);
  coll.push_back(li4);
  coll.push_back(li3);
  for_each(coll.begin(), coll.end(), printCollection);
  cout << endl;
  sort(coll.begin(), coll.end(), LessForCollection);
  for_each(coll.begin(), coll.end(), printCollection);
  return 0;
}

