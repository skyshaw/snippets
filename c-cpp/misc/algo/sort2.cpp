#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <boost/assign.hpp>
#include "algostuff.hpp"

using namespace std;
using namespace boost;

bool LessLength(const string& lhs, const string& rhs) {
  return lhs.length() < rhs.length();
}

int main() {
  using namespace boost::assign;
  vector<string> coll1 = (list_of("1xxx")
                          ("2x")
                          ("3x")
                          ("4x")
                          ("5xx")
                          ("6xxx")
                          ("7xx")
                          ("8xxx")
                          ("9xx")
                          ("10xxxx")
                          ("11")
                          ("12")
                          ("13")
                          ("14xx")
                          ("15")
                          ("16")
                          ("17"));
  vector<string> coll2 = coll1;
  sort(coll1.begin(), coll1.end(), LessLength);
  PRINT_ELEMENTS(coll1);
  stable_sort(coll2.begin(), coll2.end(), LessLength);
  PRINT_ELEMENTS(coll2);
  return 0;
}
