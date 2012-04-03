#include <iostream>
#include <iterator>
#include <algorithm>
#include <functional>
#include <list>
#include "algostuff.hpp"

using namespace std;

int main() {
  int source[] = {1, 4, 4, 6, 1, 2, 2, 3, 1, 6, 6, 6, 5, 7, 5, 4, 4};
  int sourceNum = sizeof(source) / sizeof(source[0]);
  list<int> coll;
  copy(source, source + sourceNum,
       back_inserter(coll));
  PRINT_ELEMENTS(coll);
  list<int>::iterator pos;
  pos = unique(coll.begin(), coll.end());
  copy(coll.begin(), pos,
       ostream_iterator<int>(cout, " "));
  cout << endl;
  copy(source, source + sourceNum, coll.begin());
  coll.erase(unique(coll.begin(), coll.end(),
                    greater<int>()),
             coll.end());
  copy(coll.begin(), coll.end(),
       ostream_iterator<int>(cout, " "));
  cout << endl;
  return 0;
}
