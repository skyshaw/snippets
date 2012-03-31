#include <fstream>
#include <vector>
#include <boost/progress.hpp>

using namespace std;
using namespace boost;

int main() {
  vector<string> v(100, "aaa");
  ofstream ofs("a.txt");
  progress_display pd(v.size());
  vector<string>::iterator pos;
  for (pos = v.begin(); pos != v.end(); ++pos) {
    ofs << *pos << endl;
    sleep(1);
    ++pd;
  }
  return 0;
}
