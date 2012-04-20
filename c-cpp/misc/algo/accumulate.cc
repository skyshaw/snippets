#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <functional>
#include "algostuff.hpp"

using namespace std;

int main() {
  vector<int> coll;
  INSERT_ELEMENTS(coll, 1, 9);
  cout << accumulate(coll.begin(), coll.end(), 0) << endl;
  cout << accumulate(coll.begin(), coll.end(), -100) << endl;
  cout << accumulate(coll.begin(), coll.end(), 1, multiplies<int>()) << endl;
  cout << accumulate(coll.begin(), coll.end(), 0, multiplies<int>()) << endl;
  return 0;
}
