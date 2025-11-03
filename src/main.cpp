#include <iostream>
#include <memory>

#include <os_api/screen.hpp>
#include <os_api/window.hpp>
#include <graphics/face.hpp>
#include <graphics/point.hpp>
#include <graphics/camera.hpp>

using namespace std;
using namespace os_api;
using namespace graphics;

int main() {
    Window my_window(1500, 2000);
    Camera my_camera(10, 15);

    Face A(make_shared<Point_3D>(0, 0, 0), make_shared<Point_3D>(7, 3, 0), make_shared<Point_3D>(2, 5, 0));

    cout << A.to_string() << endl;

    my_camera.render(my_window.get_screen(), A);

    my_camera.move(Point_3D(7, 3, 0));

    my_window.get_screen().flush();

    my_camera.render(my_window.get_screen(), A);

    my_window.refresh();

    // Pause program
    int useless;
    cin >> useless;

    return 0;
}