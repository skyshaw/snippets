#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


class MeanValue {
 public:
  MeanValue(): num(0), sum(0) {
  }
  void operator()(int elem) {
    ++num;
    sum += elem;
  }
  int value() {
    return static_cast<double>(sum) / static_cast<double>(num);
  }
 private:
  int num, sum;
};

int main() {
  vector<int> coll;
  for (int i = 1; i <= 9; ++i) coll.push_back(i);
  MeanValue mv = for_each(coll.begin(), coll.end(), MeanValue());
  cout << mv.value() << endl;
  return 0;
}
