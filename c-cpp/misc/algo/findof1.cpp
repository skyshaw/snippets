#include <iostream>
#include <algorithm>
#include <vector>
#include "algostuff.hpp"

using namespace std;

int main() {
  vector<int> coll; 
  INSERT_ELEMENTS(coll, 1, 11);
  vector<int> subcoll;
  INSERT_ELEMENTS(subcoll, 3, 5);
  PRINT_ELEMENTS(coll);
  PRINT_ELEMENTS(subcoll);
  vector<int>::iterator pos;
  pos = find_first_of(coll.begin(), coll.end(),
                      subcoll.begin(), subcoll.end());
  cout << distance(coll.begin(), pos) + 1 << endl;
  vector<int>::reverse_iterator rpos;
  rpos = find_first_of(coll.rbegin(), coll.rend(),
                       subcoll.begin(), subcoll.end());
  cout << distance(coll.begin(), rpos.base()) << endl;
  return 0;
}
