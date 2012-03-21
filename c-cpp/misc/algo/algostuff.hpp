#ifndef _ALGOSTUFF_H_
#define _ALGOSTUFF_H_
#include <iostream>
template <class T> 
inline void PRINT_ELEMENTS(const T& container, const char* opstr = "") {
  typedef typename T::const_iterator iter;
  std::cout << opstr;
  for (iter pos = container.begin(); pos != container.end(); ++pos) {
    std::cout << *pos << ' ';
  }
  std::cout << std::endl;
}

template <class T>
inline void INSERT_ELEMENTS(T& container, int first, int last) {
  for (int i = first; i <= last; ++i) {
    container.insert(container.end(), i);
  }
}
#endif
