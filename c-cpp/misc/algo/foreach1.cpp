#include <iostream>
#include <algorithm>
#include <vector>
#include "algostuff.hpp"

using namespace std;

void print(int elem) {
  cout << elem << ' ';
}

int main() {
  vector<int> vec;
  INSERT_ELEMENTS(vec, 1, 9);
  PRINT_ELEMENTS(vec);
  for_each(vec.begin(), vec.end(), print);
  cout << endl;
  return 0;
} 
