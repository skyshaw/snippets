#include <iostream>
#include <algorithm>
#include <vector>
#include "algostuff.hpp"

using namespace std;

int main() {
  vector<int> coll;
  INSERT_ELEMENTS(coll, 1, 3);
  PRINT_ELEMENTS(coll);
  while (next_permutation(coll.begin(), coll.end())) {
    PRINT_ELEMENTS(coll);
  }
  
  PRINT_ELEMENTS(coll, "after next:\n");
  while (prev_permutation(coll.begin(), coll.end())) {
    PRINT_ELEMENTS(coll);
  }
  cout << endl;
  PRINT_ELEMENTS(coll);
  while (prev_permutation(coll.begin(), coll.end())) {
    PRINT_ELEMENTS(coll);
  }
  //if sequence is 1 2 3, prev_permutation return false, but 1 2 3 -> 3 2 1
  //if sequence is 3 2 1, next_permutation return false, but 3 2 1 -> 1 2 3
  return 0;
}
