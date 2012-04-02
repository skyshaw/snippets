#include <iostream>
#include <algorithm>
#include <list>
#include <functional>
#include "algostuff.hpp"

using namespace std;

int main() {
  list<int> coll;
  INSERT_ELEMENTS(coll, 2, 6);
  INSERT_ELEMENTS(coll, 4, 9);
  INSERT_ELEMENTS(coll, 1, 7);
  PRINT_ELEMENTS(coll);
  list<int>::iterator pos;
  pos = remove(coll.begin(), coll.end(), 5);
  PRINT_ELEMENTS(coll);
  coll.erase(pos, coll.end());
  PRINT_ELEMENTS(coll);
  coll.erase(remove_if(coll.begin(), coll.end(),
                       bind2nd(less<int>(), 4)),
             coll.end());
  PRINT_ELEMENTS(coll);
  return 0;
}
