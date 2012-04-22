#include <iostream>
#include <algorithm>
#include <iterator>
#include <list>

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
  generate_n(back_inserter(coll), 9, IntSequence(1));
  copy(coll.begin(), coll.end(),
       ostream_iterator<int>(cout, " "));
  cout << endl;
  generate(++coll.begin(), --coll.end(), IntSequence(42));
  copy(coll.begin(), coll.end(),
       ostream_iterator<int>(cout, " "));
  cout << endl;
  return 0;
}
