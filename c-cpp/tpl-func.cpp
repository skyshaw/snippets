#include <iostream>

//#define TEST

#ifdef TEST
template <class T> 
void foo(T) {
    std::cout << "foo(T)" << std::endl;
}

template <class T> 
void foo(T*) { 
    std::cout << "foo(T*)" << std::endl;
}

template <> 
void foo<int>(int*) { 
    std::cout << "foo<int>(int*)" << std::endl;
}
#else
template <class T> 
void foo(T) {
    std::cout << "foo(T)" << std::endl;
}

template <> 
void foo<int*>(int*) { 
    std::cout << "foo<int>(int*)" << std::endl;
}

template <class T> 
void foo(T*) { 
    std::cout << "foo(T*)" << std::endl;
}
#endif

int main(int argc, char **argv) {
    int* p = 0;
    foo(p);
    return 0;
}
