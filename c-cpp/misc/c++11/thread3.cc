#include <iostream>
#include <thread>
#include <string>

using namespace std;

class SaylHello{
 public:
  void func(const string &name) {
    cout <<"Hello " << name << endl;
  }
};

int main(int argc, char* argv[])
{
  SaylHello x;

  thread p(&SaylHello::func, &x, "Tom");

  thread q([](string name) {
             cout << "Hello " << name << endl;
           }, "Jom");

  p.join();
  q.join();

  return 0;
}
