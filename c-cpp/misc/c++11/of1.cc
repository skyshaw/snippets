#include <iostream>
#include <algorithm>
#include <vector>

int main() {
  std::vector<int> v = {1, 2, -1, 0, 4, 5};
  std::cout << all_of(v.begin(), v.end(), [](int val) { return val > 0; }) << '\n';
  std::cout << any_of(v.begin(), v.end(), [](int val) { return val > 0; }) << '\n';
  std::cout << none_of(v.begin(), v.end(), [](int val) { return val > 0; }) << '\n';
  return 0;
}
