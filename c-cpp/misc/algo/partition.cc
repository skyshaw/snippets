#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include "algostuff.hpp"

using namespace std;

int main() {
  vector<int> coll1;
  vector<int> coll2;
  INSERT_ELEMENTS(coll1, 1, 9);
  INSERT_ELEMENTS(coll2, 1, 9);
  PRINT_ELEMENTS(coll1);
  vector<int>::iterator pos;
  pos = partition(coll1.begin(), coll1.end(),
                  not1(bind2nd(modulus<int>(), 2)));
  cout << *pos << endl;
  PRINT_ELEMENTS(coll1);

  PRINT_ELEMENTS(coll2);
  pos = stable_partition(coll2.begin(), coll2.end(),
                         not1(bind2nd(modulus<int>(), 2)));
  cout << *pos << endl;
  PRINT_ELEMENTS(coll2);
  return 0;
}
