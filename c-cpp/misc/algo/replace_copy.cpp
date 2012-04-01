#include <iostream>
#include <functional>
#include <algorithm>
#include <iterator>
#include <list>
#include "algostuff.hpp"

using namespace std;

int main() {
  list<int> coll;
  INSERT_ELEMENTS(coll, 2, 6);
  INSERT_ELEMENTS(coll, 4, 9);
  PRINT_ELEMENTS(coll);
  replace_copy(coll.begin(), coll.end(),
               ostream_iterator<int>(cout, " "), 5, 55);
  cout << endl;
  replace_copy_if(coll.begin(), coll.end(),
               ostream_iterator<int>(cout, " "),
               bind2nd(less<int>(), 5), 42);
  cout << endl;
  replace_copy_if(coll.begin(), coll.end(),
                  ostream_iterator<int>(cout, " "),
                  bind2nd(modulus<int>(), 2), 0);
  cout << endl;
  return 0;
}
