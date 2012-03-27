#include <iostream>
#include <boost/timer.hpp>
using namespace boost;
using namespace std;

int main() {
  timer t;
  cout << "max timespan:" << t.elapsed_max() / 3600 << "h" << endl;
  cout << "min timespan:" << t.elapsed_min() << "s" << endl;
  cout << "now time elapse:" << t.elapsed() << "s" << endl;
  return 0;
}
