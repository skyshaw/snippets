#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <utility>
#include "algostuff.hpp"

using namespace std;

int main() {
  vector<int> coll1;
  INSERT_ELEMENTS(coll1, 1, 6);
  vector<int> coll2;
  for (int i = 1; i <= 16; i *= 2)
    coll2.push_back(i);
  coll2.push_back(3);
  PRINT_ELEMENTS(coll1);
  PRINT_ELEMENTS(coll2);
  pair<vector<int>::const_iterator, vector<int>::const_iterator> pos;
  pos = mismatch(coll1.begin(), coll2.begin(),
                 coll2.begin());
  if (pos.first == coll1.end()) {
    cout << "no value mismatch" << endl;
  } else {
    cout << "fisrt mismatch found: "
        << *pos.first << " "
        << *pos.second << endl;
  }

  pos = mismatch(coll1.begin(), coll1.end(),
                 coll2.begin(),
                 less_equal<int>());
  if (pos.first == coll1.end()) {
    cout << "no value greater" << endl;
  } else {
    cout << "value greater found: "
        << *pos.first << " "
        << *pos.second << endl;
  }
  return 0;
}
