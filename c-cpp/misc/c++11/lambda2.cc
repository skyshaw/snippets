#include <iostream>

using namespace std;

int main() {
  int result = []() -> int { return 4; }();
  cout << result << endl;
  result = [](int input) -> int { return 2 * input; }(10);
  cout << result << endl;
  auto foo = [](int a, int b) -> int { return a + b; };
  cout << foo(1, 3) << endl;
  return 0;
}

