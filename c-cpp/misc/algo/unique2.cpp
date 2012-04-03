#include <iterator>
#include <algorithm>
#include <functional>
#include <list>
#include "algostuff.hpp"

using namespace std;

bool differenceOne(int elem1, int elem2) {
  return elem1 - 1 == elem2 || elem2 - 1 == elem1;
}

int main() {
  int source[] = {1, 4, 4, 6, 1, 2, 2, 3, 1, 6, 6, 6, 5, 7, 5, 4, 4};
  int sourceNum = sizeof(source) / sizeof(source[0]);
  list<int> coll;
  copy(source, source + sourceNum,
       back_inserter(coll));

  PRINT_ELEMENTS(coll);
  unique_copy(coll.begin(), coll.end(),
              ostream_iterator<int>(cout, " "));
  cout << endl;
  unique_copy(coll.begin(), coll.end(),
              ostream_iterator<int>(cout, " "),
              differenceOne);
  cout << endl;
  return 0;
}
