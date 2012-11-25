// http://the-witness.net/news/2012/11/scopeexit-in-c11/
// Change MakeScopeExit([=](){code;}) To MakeScopeExit([=](){code;})

#include <iostream>
template <typename F>
struct ScopeExit {
    ScopeExit(F f) : f(f) {}
    ~ScopeExit() { f(); }
    F f;
};

template <typename F>
ScopeExit<F> MakeScopeExit(F f) {
    return ScopeExit<F>(f);
};
#define STRING_JOIN2(arg1, arg2) DO_STRING_JOIN2(arg1, arg2)
#define DO_STRING_JOIN2(arg1, arg2) arg1 ## arg2
#define SCOPE_EXIT(code) \
    auto STRING_JOIN2(scope_exit_, __LINE__) = MakeScopeExit([&](){code;})


struct Foo {
	void close() {
		std::cout << "Foo Closed" << std::endl;
	}
};

int main() {
	{
		Foo foo;
		SCOPE_EXIT(foo.close());
	}
	return 0;
}