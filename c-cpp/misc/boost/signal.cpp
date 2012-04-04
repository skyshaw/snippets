#include <iostream>
#include <boost/signals2.hpp>

using namespace std;
using namespace boost;

void slot1() {
  cout << "slot1" << endl;
}

void slot2() {
  cout << "slot2" << endl;
}

int main() {
  signals2::signal<void()> sig;
  sig.connect(&slot1);
  sig.connect(&slot2);
  sig();
  return 0;
}
