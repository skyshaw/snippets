#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;

bool bothSpace(char elem1, char elem2) {
  return elem1 == ' ' && elem2 == ' ';
}

int main() {
  cin.unsetf(ios::skipws);
  unique_copy(istream_iterator<char>(cin),
              istream_iterator<char>(),
              ostream_iterator<char>(cout),
              bothSpace);
  return 0;
}
