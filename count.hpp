#ifndef _COUNT_H_
#define _COUNT_H_
#include <cstddef>
//
// 子类以private方式继承此类, 如
// class Foo: private Counted<Foo> 
//
// 实现文件中必须增加maxObjects的定义, 如 
// template<>
// const size_t Counted<Foo>::maxObjects = 10;
//
// 要在子类接口中引入函数objectCount及异常TooManyObjects
// 可以在子类public接口中使用using declaration，如
// using Counted<Foo>::objectCount;
// using Counted<Foo>::TooManyObjects;
//
template <class BeingCounted>
class Counted {
public:
    class TooManyObjects { 
    };
    static int objectCount() {
        return numObjects;
    }
protected:    
    Counted();
    Counted(const Counted& rhs);
    ~Counted() {
        --numObjects;
    }
private:
    static int numObjects;
    static const size_t maxObjects;
    void init();
};

template <class BeingCounted>
int Counted<BeingCounted>::numObjects;

template <class BeingCounted>
Counted<BeingCounted>::Counted() {
    init();
}

template <class BeingCounted>
Counted<BeingCounted>::Counted(const Counted<BeingCounted>&) {
    init();
}

template <class BeingCounted>
void Counted<BeingCounted>::init() {
    if (numObjects >= maxObjects) throw TooManyObjects();
    ++numObjects;
}
#endif
