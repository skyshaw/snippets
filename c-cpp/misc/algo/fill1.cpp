#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>
#include <string>
#include "algostuff.hpp"

using namespace std;

int main() {
  fill_n(ostream_iterator<float>(cout, " "), 10, 7.7);
  cout << endl;

  list<string> coll;
  fill_n(back_inserter(coll), 9, "hello");
  PRINT_ELEMENTS(coll);

  fill(coll.begin(), coll.end(), "again");
  PRINT_ELEMENTS(coll);

  fill_n(coll.begin(), coll.size() - 2, "hi");
  PRINT_ELEMENTS(coll);

  list<string>::iterator pos1 = coll.begin();
  list<string>::iterator pos2 = coll.end();
  fill(++pos1, --pos2, "hmmm");
  PRINT_ELEMENTS(coll);
  return 0;
}
