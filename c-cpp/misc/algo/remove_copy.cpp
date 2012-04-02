#include <iostream>
#include <iterator>
#include <functional>
#include <algorithm>
#include <list>
#include <set>
#include "algostuff.hpp"

using namespace std;

int main() {
  list<int> coll1;
  INSERT_ELEMENTS(coll1, 1, 6);
  INSERT_ELEMENTS(coll1, 1, 9);
  PRINT_ELEMENTS(coll1);
  remove_copy(coll1.begin(), coll1.end(),
              ostream_iterator<int>(cout, " "),
              3);
  cout << endl;
  remove_copy_if(coll1.begin(), coll1.end(),
                 ostream_iterator<int>(cout, " "),
                 bind2nd(greater<int>(), 4));
  cout << endl;
  multiset<int> coll2; //multiset will keep order itself
  remove_copy_if(coll1.begin(), coll1.end(),
                 inserter(coll2, coll2.end()),
                 bind2nd(less<int>(), 4));
  PRINT_ELEMENTS(coll2);

  return 0;
}
