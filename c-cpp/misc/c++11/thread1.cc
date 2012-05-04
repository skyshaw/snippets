#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <vector>

using namespace std;

void printer(string text, int num_times, int time_between) {
  for (int i = 0; i < num_times; ++i) {
    cout << text << endl;
    std::chrono::milliseconds duration(time_between);
    std::this_thread::sleep_for(duration);
  }
}

int main() {
  vector<thread> printers;
  printers.push_back(thread(printer, "Hello", 30, 10));
  printers.push_back(thread(printer, "World", 40, 15));
  printers.push_back(thread(printer, "Parallel World", 40, 20));
  for (auto &p : printers)  {
    p.join();
  }
  return 0;
}
