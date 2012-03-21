#include <memory>
#include <iostream>

#define WEAK_PTR

#ifdef WEAK_PTR
struct Bar;

struct Foo {
    ~Foo() {
        std::cout << "Foo dtor" << std::endl;
    }
    std::shared_ptr<Bar> pBar;
};

struct Bar {
    ~Bar() {
        std::cout << "Bar dtor" << std::endl;
    }        
    std::weak_ptr<Foo> pFoo;
};

int main(int argc, char** argv) {
    std::shared_ptr<Foo> aFoo(new Foo());
    std::shared_ptr<Bar> aBar(new Bar());
    aFoo->pBar = aBar;
    aBar->pFoo = aFoo;
    return 0;
}

#else

struct Bar;

struct Foo {
    ~Foo() {
        std::cout << "Foo dtor" << std::endl;
    }
    std::shared_ptr<Bar> pBar;
};

struct Bar {
    ~Bar() {
        std::cout << "Bar dtor" << std::endl;
    }        
    std::shared_ptr<Foo> pFoo;
};

int main(int argc, char** argv) {
    std::shared_ptr<Foo> aFoo(new Foo());
    std::shared_ptr<Bar> aBar(new Bar());
    aFoo->pBar = aBar;
    aBar->pFoo = aFoo;
    return 0;
}

#endif


