#include <iostream>
#include <sstream>
#include <boost/progress.hpp>

using namespace std;
using namespace boost;
int main() {
  stringstream ss;
  {
    progress_timer t(ss);
  }
  cout << ss.str();
  return 0;
}
