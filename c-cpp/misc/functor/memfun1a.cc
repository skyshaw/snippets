#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <boost/assign.hpp>
#include "algostuff.hpp"

using namespace std;

class Person {
 public:
  Person(string name) : name_(name) {}
  void print() const {
    cout << name_ << endl;
  }
  void printWithPrefix(string prefix) {
    cout << prefix << name_ << endl;
  }
 private:
  string name_;
};

int main() {
  using namespace boost::assign;
  vector<Person> coll = list_of("Tom")("Jim")("John")("Kate");
  for_each(coll.begin(), coll.end(),
           mem_fun_ref(&Person::print));
  for_each(coll.begin(), coll.end(),
           bind2nd(mem_fun_ref(&Person::printWithPrefix), "name: "));
  return 0;
}
