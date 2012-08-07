#include <iostream>
#include <algorithm>


template <typename ForwardInterator>
void odd_sort(ForwardInterator beg, ForwardInterator end) {
  ForwardInterator EvenBegIter = beg;
  while ((*EvenBegIter) % 2 != 0) {
    ++EvenBegIter;
  }
  if (EvenBegIter == end) return;
  for (ForwardInterator it = ++EvenBegIter; it != end; ++it) {
    if ((*it) % 2 != 0) {
      std::iter_swap(EvenBegIter, it);
      ++EvenBegIter;
    }
  }
}

int main() {
  return 0;
}
