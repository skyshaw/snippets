#include <iostream>
#include <algorithm>
#include <vector>
#include "algostuff.hpp"

using namespace std;

int main() {
  vector<int> coll;
  INSERT_ELEMENTS(coll, 1, 9);
  if (binary_search(coll.begin(), coll.end(), 5)) {
    cout << "5 in coll" << endl;
  } else {
    cout << "5 not in coll" << endl;
  }

  if (binary_search(coll.begin(), coll.end(), 42)) {
    cout << "42 in coll" << endl;
  } else {
    cout << "42 not in coll" << endl;
  }
  return 0;
}
