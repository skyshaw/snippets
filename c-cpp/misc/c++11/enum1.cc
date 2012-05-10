#include <iostream>

using namespace std;


enum Alert {
  green,
  yellow,
  election,
  red
};

enum class Color {
  red,
  blue
};

enum class TrafficLight {
  red,
  yellow,
  green
};

int main() {

#ifdef ERROR
  Alert a = 7;
  Color c = 7;
#endif 
  int a2 = red;
#ifdef ERROR
  int a3 = Alert::red;
  int a4 = blue;
  int a5 = Color::blue;
#endif



  return 0;
}
