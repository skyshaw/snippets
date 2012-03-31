#include <algorithm>
#include <string>
#include <utility>
#include <cctype>
#include <list>
#include <cassert>
#include <iostream>
#include <iterator>

class NFA {
 public:
  NFA(const std::string& re) : re_(re) {
    pos = re_.begin();
    get_token();
    nfa = build_nfa();
    assert(re_.end() == pos);
  }

 private:

  class edge;
  struct node {
   public:
    void add(node* dst, int ch) {
      adj.push_back(edge(dst, ch));
    }
   private:
    std::list<edge> adj;
  };

  class edge {
   public:
    edge(node* dst = NULL, int ch = 0) : dest(dst), wei(ch) {}
   private:
    node* dest;
    int wei;
  };
  typedef std::pair<node*, node*> nfa_node;

  nfa_node build_nfa() {
    int ch = token;
    if (::isalpha(ch)) {
      return single(ch);
    } else {
      match('(');
      nfa_node nfa1 = build_nfa();
      node *src = NULL, *dst = NULL;
      ch = token;
      switch (ch) {
        case '*': {
          src = new node();
          dst = new node();
          src->add(nfa1.first, 0);
          src->add(dst, 0);
          nfa1.second->add(nfa1.first, 0);
          nfa1.second->add(dst, 0);
          match('*');
          match(')');
          break;
        }
        case '|': {
          match('|');
          src = new node();
          dst = new node();
          nfa_node nfa2 = build_nfa();
          src->add(nfa1.first, 0);
          src->add(nfa2.first, 0);
          nfa1.second->add(dst, 0);
          nfa2.second->add(dst, 0);
          match(')');
          break;
        }
        default: {
          nfa_node nfa2 = build_nfa();
          nfa1.second->add(nfa2.first, 0);
          src = nfa1.first;
          dst = nfa2.second;
          match(')');
          break;
        }
      }
      return std::make_pair(src, dst);
    }
  }

  nfa_node single(int ch) {
    get_token();
    node* src = new node();
    node* dst = new node();
    src->add(dst, ch);
    return std::make_pair(src, dst);
  }

  void match(int ch) {
    if (ch == token) 
      get_token();
    else {
      std::cout << "error" << std::endl;
      exit(0);
    }
  }

  void get_token() {
    if (pos == re_.end())
      token = -1;
    else
      token = *pos++;
    std::cout << *pos << std::endl;
  }

 private:
  std::string::const_iterator pos;
  const std::string& re_;
  nfa_node nfa;
  int token;
};

int main() {
  std::string re("((a*)(b(a*)))");
  NFA nfa(re);
  return 0;
}
