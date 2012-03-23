#include <algorithm>
#include <iostream>
#include <deque>
#include "algostuff.hpp"

using namespace std;

bool absLess(const int lhs, const int rhs) {
  return abs(lhs) < abs(rhs);
}

int main() {
  deque<int> coll;
  INSERT_ELEMENTS(coll, 5, 7);
  INSERT_ELEMENTS(coll, -8, 3);
  int mi = *min_element(coll.begin(), coll.end()); 
  std::cout << mi << std::endl;
  int ma = *max_element(coll.begin(), coll.end()); 
  std::cout << ma << std::endl;
  int absmi = *min_element(coll.begin(), coll.end(), absLess);
  std::cout << absmi << std::endl;
  int absma = *max_element(coll.begin(), coll.end(), absLess);
  std::cout << absma << std::endl;
  return 0;
}
