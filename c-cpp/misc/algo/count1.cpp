#include <algorithm>
#include <iostream>
#include <deque>
#include <functional>
#include "algostuff.hpp"

using namespace std;

bool isEven(int value) {
  return value % 2 == 0;
}

int main() {
  deque<int> coll;
  INSERT_ELEMENTS(coll, 1, 9);
  coll.push_back(4);
  int cnt1 = count(coll.begin(), coll.end(), 4);
  std::cout << cnt1 << std::endl;
  int cnt2 = count_if(coll.begin(), coll.end(), isEven);
  std::cout << cnt2 << std::endl;
  int cnt3 = count_if(coll.begin(), coll.end(), bind2nd(greater<int>(), 4));
  std::cout << cnt3 << std::endl;
  return 0; 
}
