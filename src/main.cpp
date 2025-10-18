#include <iostream>
#include "screen/screen.hpp"

using namespace std;
using namespace screen;

int main() {
  Screen my_screen(10, 10);
  my_screen.show();
  my_screen.set_pixel(0,0, true);
  my_screen.show();
  my_screen.set_pixel(0,3, true);
  my_screen.show();
  my_screen.flush();
  my_screen.show();
  return 0;
}