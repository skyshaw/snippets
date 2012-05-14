#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main() {
  string input;
  regex integer("(\\+|-)?[[:digit:]]+");
  while (true) {
    cout << "Give me an integer!" << endl;
    if (input == "q") 
      break;
    else if (regex_match(input, integer))
      cout << "integer" << endl;
    else 
      cout << "Invalid input << endl" << endl;
  }
  return 0;
}
