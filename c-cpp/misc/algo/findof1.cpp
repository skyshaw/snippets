#include <iostream>
#include <algorithm>
#include <vector>
#include "algostuff.hpp"

using namespace std;

int main() {
  vector<int> coll; 
  INSERT_ELEMENTS(coll, 1, 11);
  vector<int> searchcoll;
  INSERT_ELEMENTS(searchcoll, 3, 5);
  PRINT_ELEMENTS(coll);
  PRINT_ELEMENTS(searchcoll);
  vector<int>::iterator pos;
  pos = find_first_of(coll.begin(), coll.end(),
                      searchcoll.begin(), searchcoll.end());
  cout << distance(coll.begin(), pos) + 1 << endl;
  vector<int>::reverse_iterator rpos;
  rpos = find_first_of(coll.rbegin(), coll.rend(),
                       searchcoll.begin(), searchcoll.end());
  cout << distance(coll.begin(), rpos.base()) << endl;
  return 0;
}
