#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main() {
  regex number("(\\+|-)?[[:digit:]]+(\\.(([[:digit:]]+)?))?((e|E)(\\+|-)?[[:digit:]]+)");
  regex word("[[:alpha:]]+");
  string input, clean_words, clean_numbers;
  const string format = "";
  getline(cin, input);
  clean_numbers = regex_replace(input, number,
                                format, regex_constants::format_default);
  clean_words = regex_replace(input, word,
                              format, regex_constants::format_default);
  cout << clean_words << endl;
  cout << clean_numbers << endl;
  return 0;
}
