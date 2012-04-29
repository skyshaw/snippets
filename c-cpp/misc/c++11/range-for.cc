#include <iostream>
#include <vector>
#include <boost/assign.hpp>

using namespace std;

void foo(vector<int>& v) {
  for (auto x: v) cout << x << '\n';
  for (auto& x: v) ++x;
  for (auto x: v) cout << x << '\n';
}

void bar() {
  for (const auto x : {1, 2, 3, 5, 6, 13, 21, 34})
    cout << x << '\n';
}

int main() {
  using namespace boost::assign;
  vector<int> coll = list_of(1)(2)(3)(4);
  foo(coll);
  bar();
  return 0;
}
