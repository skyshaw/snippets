#include <iostream>
#include <algorithm>
#include <vector>
#include "algostuff.hpp"

using namespace std;

int main() {
  vector<char> source(10, '.');
  for (char c = 'a'; c <= 'f'; ++c)
    source.push_back(c);
  source.insert(source.end(), 10, '.');
  PRINT_ELEMENTS(source);
  vector<char> coll1(source.begin(), source.end());
  copy(coll1.begin() + 10, coll1.begin() + 16,
       coll1.begin() + 7);
  PRINT_ELEMENTS(coll1);
  vector<char> coll2(source.begin(), source.end());
  copy_backward(coll2.begin() + 10, coll2.begin() + 16,
                coll2.begin() + 19);
  PRINT_ELEMENTS(coll2);
  return 0;
}
