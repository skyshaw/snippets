#include <iostream>
#include <algorithm>
#include <iterator>
#include <list>
#include "algostuff.hpp"

using namespace std;

class IntSequence {
 public:
  IntSequence(int InitValue): value(InitValue) {
  }
  int operator() () {
    return value++;
  }
 private:
  int value;
};

int main() {
  list<int> coll;
  IntSequence seq(1);
  generate_n<back_insert_iterator<list<int> >, int, IntSequence&>(back_inserter(coll), 4, seq);
  PRINT_ELEMENTS(coll);
  generate_n(back_inserter(coll), 4, IntSequence(42));
  PRINT_ELEMENTS(coll);
  generate_n(back_inserter(coll), 4, seq); 
  PRINT_ELEMENTS(coll);
  generate_n(back_inserter(coll), 4, seq); 
  PRINT_ELEMENTS(coll);

  return 0;
}
