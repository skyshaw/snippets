#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

struct Record {
  Record(const std::string& name, int age): name_(name), age_(age) {
  }
  std::string name_;
  int age_;
};

int main() {
  std::vector<int> v = {50, -10, 20, -30};
  std::sort(v.begin(), v.end(), [](int a, int b) { return abs(a) < abs(b); });
  std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
  std::cout << '\n';
  std::vector<Record> coll = {{"Tom", 10}, {"Jim", 11}, {"John", 3}, {"Kate", 5}};
  std::vector<int> indices(coll.size());
  int count = 0;
  generate(indices.begin(),indices.end(), [&count]() { return count++; });
  std::copy(indices.begin(), indices.end(), std::ostream_iterator<int>(std::cout, " "));
  std::cout << '\n';
  std::sort(indices.begin(), indices.end(),
            [&](int a, int b) { return coll[a].name_ < coll[b].name_; });
  std::copy(indices.begin(), indices.end(), std::ostream_iterator<int>(std::cout, " "));
  std::cout << '\n';
  std::for_each(indices.begin(), indices.end(),
                [&](int idx) { std::cout << coll[idx].name_ << " " << coll[idx].age_ << '\n'; });
  return 0;
}
