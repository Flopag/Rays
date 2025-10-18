#include <iostream>
#include <memory>
#include <cmath>
#include "screen/screen.hpp"
#include "graphics/face.hpp"
#include "graphics/point.hpp"

using namespace std;
using namespace screen;
using namespace graphics;

int main() {
  Screen my_screen(30, 30);
  my_screen.show();

  Face A(make_shared<Point_3D>(10, 10, 0), make_shared<Point_3D>(20, 11, 0), make_shared<Point_3D>(9, 20, 0));

  cout << A.to_string() << endl;

  Point_3D origin(10, 10, 0);
  Point_3D rotations(0, 0, 0);

  for(shared_ptr<Point_3D> point : A.get_points()){
    Point_2D a = point->projection(origin, rotations);
    my_screen.set_pixel(round(a.get_y())+15, round(a.get_x())+15, true);
  }

  my_screen.show();

  my_screen.flush();

  origin = Point_3D(10, 10, 0);
  rotations = Point_3D(0, 0, 0);

  while(1){
    string input;
    cin >> input;
    my_screen.flush();

    if(input == "d")
      rotations.move(rotations.get_x()+5, rotations.get_y(), rotations.get_z());
    if(input == "g")
      rotations.move(rotations.get_x(), rotations.get_y()+5, rotations.get_z());

    cout << rotations.to_string() << endl;

    for(shared_ptr<Point_3D> point : A.get_points()){
      Point_2D a = point->projection(origin, rotations);
      my_screen.set_pixel(round(a.get_y()+15), round(a.get_x()+15), true);
    }

    my_screen.show();
  }

  return 0;
}