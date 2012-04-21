#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <numeric>
#include "algostuff.hpp"

using namespace std;

int main() {
  vector<int> coll;
  INSERT_ELEMENTS(coll, 1, 6);
  cout << inner_product(coll.begin(), coll.end(),
                        coll.begin(), 0) << endl;
  cout << inner_product(coll.begin(), coll.end(),
                        coll.rbegin(), 0) << endl;
  cout << inner_product(coll.begin(), coll.end(),
                        coll.begin(), 1,
                        multiplies<int>(),
                        plus<int>()) << endl;
  return 0;
}

