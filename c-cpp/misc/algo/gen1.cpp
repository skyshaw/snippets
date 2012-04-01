#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>
#include "algostuff.hpp"

using namespace std;

int main() {
  list<int> coll;
  generate_n(back_inserter(coll), 5, rand);
  PRINT_ELEMENTS(coll);
  generate(coll.begin(), coll.end(), rand);
  PRINT_ELEMENTS(coll);
  return 0;
}
