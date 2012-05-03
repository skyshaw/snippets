#ifndef _PRIME_ARRAY_H_
#define _PRIME_ARRAY_H_

#include <tr1/memory>
#include <vector>

class prime_array {
 public:
  prime_array(int upperbound) {
    std::tr1::shared_ptr<std::vector<bool> > prime(
        new std::vector<bool>(upperbound, true));
    long long i, j;
    for (i = 2; i < upperbound; ++i)
      if ((*prime)[i])
        for (j = i * i; j < upperbound; j += i)
          (*prime)[j] = false;
    for (i = 2; i < upperbound; ++i)
      if ((*prime)[i])
        array.push_back(i);
  }

  size_t size() {
    return array.size();
  }

  int operator[](size_t index) {
    return array[index];
  }
 private:
  std::vector<int> array;
};

#endif
