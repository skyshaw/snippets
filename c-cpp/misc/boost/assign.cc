#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <utility>
#include <iterator>
#include <list>
#include <deque>
#include <boost/assign.hpp>

using namespace std;
using namespace boost;

#define OUTPUT(coll, type) \
  copy(coll.begin(), coll.end(), ostream_iterator<type>(cout, " ")); \
  cout << endl;

int main() {
  using namespace boost::assign;
  vector<int> v;
  v += 1, 2, 3, 4, 5, 6 * 6;
  push_back(v)(1)(2)(3)(4);
  OUTPUT(v, int);
  list<string> s;
  s += "cpp", "java", "c#", "python";
  push_front(s)("cpp")("java")("c#")("python");
  OUTPUT(s, string);
  map<int, string> m;
  m += make_pair(1, "one"), make_pair(2, "two");
  insert(m)(1, "one")(2, "two");

  vector<int> v2 = list_of(1)(2)(3)(4)(5);
  OUTPUT(v2, int);
  deque<string> d = (list_of("power")("bomb"), "phazon", "suit");
  OUTPUT(d, string);
  set<int> s2 = (list_of(10), 20, 30, 40, 50);
  OUTPUT(s2, int);
  map<int, int> m2 = map_list_of(1, 2)(3, 4)(5, 6);
  return 0;
}
