#include <iostream>
#include <algorithm>
#include <vector>
#include "algostuff.hpp"

using namespace std;

class Nth {
 public:
  Nth(int n): count(0), nth(n) {

  }

  bool operator() (int) {
    return ++count == nth;
  }

 private:
  int count;
  int nth;
};

int main() {
  vector<int> coll;
  INSERT_ELEMENTS(coll, 1, 9);
  PRINT_ELEMENTS(coll);
  vector<int>::iterator pos;
  pos = remove_if(coll.begin(), coll.end(), Nth(3));
  coll.erase(pos, coll.end());
  PRINT_ELEMENTS(coll);
  return 0;
}
