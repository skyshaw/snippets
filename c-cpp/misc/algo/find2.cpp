#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include "algostuff.hpp"

using namespace std;

int main() {
  vector<int> coll;
  INSERT_ELEMENTS(coll, 1, 9);
  INSERT_ELEMENTS(coll, 1, 9);
  PRINT_ELEMENTS(coll);
  vector<int>::iterator pos1 = find_if(coll.begin(), coll.end(),
                                       bind2nd(greater<int>(), 3));
  cout << "the " << distance(coll.begin(), pos1) + 1
      << ". element is first element greater than 3\n";

  vector<int>::iterator pos2 = find_if(coll.begin(), coll.end(),
                                       not1(bind2nd(modulus<int>(), 3)));
  cout << "the " << distance(coll.begin(), pos2) + 1
      << ". element is first element divisible by 3\n";

  return 0;
}
