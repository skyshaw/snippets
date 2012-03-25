#include <iostream>
#include <vector>
#include <algorithm>
#include "algostuff.hpp"

using namespace std;

bool checkEven(int elem, bool even) {
  if (even) {
    return elem % 2 == 0;
  } else {
    return elem % 2 != 0;
  }
}

int main() {
  vector<int> coll;
  INSERT_ELEMENTS(coll, 1, 9);
  PRINT_ELEMENTS(coll);
  bool arg[3] = {true, false, true};
  vector<int>::iterator pos;
  pos = search(coll.begin(), coll.end(),
               arg, arg + 3,
               checkEven);
  while (pos != coll.end()) {
    cout << distance(coll.begin(), pos) + 1 << endl;
    pos = search(++pos, coll.end(),
                 arg, arg + 3,
                 checkEven);
  }
  return 0;
}
