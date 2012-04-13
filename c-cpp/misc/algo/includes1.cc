#include <iostream>
#include <algorithm>
#include <vector>
#include <boost/assign.hpp>
#include "algostuff.hpp"

using namespace std;

int main() {
  using namespace boost::assign;
  vector<int> coll;
  INSERT_ELEMENTS(coll, 1, 9);
  vector<int> search = (list_of(3)(4)(7));
  if (includes(coll.begin(), coll.end(),
               search.begin(), search.end())) {
    cout << "includes" << endl;
  } else {
    cout << "not includes" << endl;
  }
  return 0;
}
