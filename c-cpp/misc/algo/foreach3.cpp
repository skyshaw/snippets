#include <iostream>
#include <algorithm>
#include <vector>
#include "algostuff.hpp"

using namespace std;

class MeanValue {
 public:
  MeanValue(int s): sum(s), count(0) {
  }
  void operator()(int x) {
    sum += x;
    ++count;
  }
  operator double() {
    return sum / count;
  }
 private:
  double sum;
  int count;
};

int main() {
  vector<int> vec;
  INSERT_ELEMENTS(vec, 1, 9);
  PRINT_ELEMENTS(vec);
  double ret = for_each(vec.begin(), vec.end(), MeanValue(0));
  cout << ret << endl;
  return 0;
}
