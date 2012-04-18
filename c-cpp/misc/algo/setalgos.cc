#include <iostream>
#include <algorithm>
#include <iterator>
#include "algostuff.hpp"

using namespace std;

int main() {
  int c1[] = {1, 2, 2, 4, 6, 7, 7, 9};
  int num1 = sizeof(c1) / sizeof(c1[0]);
  int c2[] = {2, 2, 2, 3, 6, 6, 8, 9};
  int num2 = sizeof(c2) / sizeof(c2[0]);
  copy(c1, c1 + num1, ostream_iterator<int>(cout, " "));
  cout << endl;
  copy(c2, c2 + num2, ostream_iterator<int>(cout, " "));
  cout << endl;
  cout << "merge: ";
  merge(c1, c1 + num1, c2, c2 + num2, ostream_iterator<int>(cout, " "));
  cout << endl;
  cout << "set_union: ";
  set_union(c1, c1 + num1, c2, c2 + num2, ostream_iterator<int>(cout, " "));
  cout << endl;
  cout << "set_intersection: ";
  set_intersection(c1, c1 + num1, c2, c2 + num2, ostream_iterator<int>(cout, " "));
  cout << endl;
  cout << "set_difference: ";
  set_difference(c1, c1 + num1, c2, c2 + num2, ostream_iterator<int>(cout, " "));
  cout << endl;
  cout << "set_symmetric_difference: ";
  set_symmetric_difference(c1, c1 + num1, c2, c2 + num2, ostream_iterator<int>(cout, " "));
  cout << endl;
  return 0;
}
