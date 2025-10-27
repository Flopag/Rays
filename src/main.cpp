#include <iostream>
#include <memory>

#include <screen/screen.hpp>
#include <graphics/face.hpp>
#include <graphics/point.hpp>

using namespace std;
using namespace screen;
using namespace graphics;

int main() {
    Screen my_screen(1000, 500);
    my_screen.show();

    Face A(make_shared<Point_3D>(25, 25, 0), make_shared<Point_3D>(700, 70, 0), make_shared<Point_3D>(12, 300, 0));

    cout << A.to_string() << endl;

    Point_3D origin(10, 10, 0);
    Point_3D rotations(0, 0, 0);
    Point_3D offset(15, 15, 0);

    A.render(my_screen, origin, rotations, offset);

    my_screen.show();

    my_screen.flush();

    origin = Point_3D(10, 10, 0);
    rotations = Point_3D(0, 0, 0);

    A.render(my_screen, origin, rotations, offset);

    my_screen.show();

    // Pause program
    int useless;
    cin >> useless;

    return 0;
}