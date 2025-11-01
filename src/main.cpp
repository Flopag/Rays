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
    Window my_window(1000, 500);
    Camera my_camera(1000, 500);

    Face A(make_shared<Point_3D>(25, 25, 0), make_shared<Point_3D>(700, 70, 0), make_shared<Point_3D>(12, 300, 0));

    cout << A.to_string() << endl;

    my_camera.render(my_window.get_screen(), A);

    my_window.get_screen().flush();

    my_camera.render(my_window.get_screen(), A);

    my_window.refresh();

    // Pause program
    int useless;
    cin >> useless;

    return 0;
}