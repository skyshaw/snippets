#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main() {
  auto x = hours(2) + minutes(35) + seconds(9);
  auto y = hours(3) + minutes(10) + seconds(1);
  cout << x.count() << " " << y.count() << endl;
  auto p = high_resolution_clock::now();
  for (int i = 0; i < 10000; ++i)
    ;
  auto q = high_resolution_clock::now();
  auto dura = q - p;
  cout << dura.count() << endl;
  return 0;
}
