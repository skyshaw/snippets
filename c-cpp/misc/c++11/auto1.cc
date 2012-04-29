#include <iostream>
#include <vector>
#include <boost/assign.hpp>

using namespace std;

template <typename T>
void printAll(const vector<T>& v) {
  for (auto it = v.begin(); it != v.end(); ++it)
    cout << *it << endl;
}

int main() {
  using namespace boost::assign;
  auto x = 7;
  auto y = 1.0 + 2.0;
  vector<int> coll = list_of(1)(2)(3)(4);
  printAll(coll);
  return 0;
}
