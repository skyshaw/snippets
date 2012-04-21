#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <boost/assign.hpp>
#include "algostuff.hpp"

using namespace std;

int main() {
  using namespace boost::assign;
  vector<int> coll = (list_of(17), (-3), (22), (13), (13), (-9));
  PRINT_ELEMENTS(coll);
  adjacent_difference(coll.begin(), coll.end(),
                      coll.begin());
  PRINT_ELEMENTS(coll);
  partial_sum(coll.begin(), coll.end(),
              coll.begin());
  PRINT_ELEMENTS(coll);
  return 0;
}
