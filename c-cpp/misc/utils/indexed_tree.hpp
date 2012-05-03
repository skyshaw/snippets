#ifndef _INDEXED_TREE_H_
#define _INDEXED_TREE_H_
#include <vector>

template <typename T>
class indexed_tree {
 public:
  indexed_tree(int sz): pArray(new std::vector<T>(sz + 1, 0)), size(sz) {
  } 

  ~indexed_tree() {
    delete pArray;
  }

  void add(int index, int key) {
    for (int i = index; i <= size; i += lowbit(i))
      (*pArray)[i] += key;
  }

  T sum(int index) {
    T ret = 0;
    for (int i = index; i > 0; i -= lowbit(i))
      ret += (*pArray)[i];
    return ret;
  }

 private:
  int lowbit(int x) {
    return x & (-x);
  }

 private:
  std::vector<T>* pArray;
  int size;
};
#endif
