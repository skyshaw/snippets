#include <iostream>
#include <vector>
class foo {
public:
    foo(int) { 
    }
private:
    int bar;
};

int main(int argc, char** argv) {
    std::vector<foo> vec;
    return 0;
}
//vector里装的类型是可以没有default-constructor的
