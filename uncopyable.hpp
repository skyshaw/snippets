#ifndef _UNCOPYABLE_H_
#define _UNCOPYABLE_H_

class Uncopyable {
protected:
    Uncopyable() {}
    ~Uncopyable() {}
private:
    Uncopyable(const Uncopyable&);
    Uncopyable& operator=(const Uncopyable&);
};
//子类可以以private继承此类以禁止拷贝
#endif
