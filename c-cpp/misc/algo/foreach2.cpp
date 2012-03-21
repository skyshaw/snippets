#include <iostream>
#include <algorithm>
#include <vector>
#include "algostuff.hpp"

using namespace std;

class AddValue {
 public:
  AddValue(int v): value(v) {
  }
  void operator()(int& elem) {
    elem += value;
  }
 private:
  int value;
};

int main() {
  vector<int> vec;
  INSERT_ELEMENTS(vec, 1, 9);
  PRINT_ELEMENTS(vec);
  for_each(vec.begin(), vec.end(), AddValue(10));
  PRINT_ELEMENTS(vec);
  return 0;
}
