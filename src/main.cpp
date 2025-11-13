#include <iostream>
#include <memory>

#include <os_api/screen.hpp>
#include <os_api/window.hpp>
#include <graphics/face.hpp>
#include <graphics/point.hpp>
#include <graphics/camera.hpp>
#include <graphics/color.hpp>

using namespace std;
using namespace os_api;
using namespace graphics;

int main() {
    Window my_window(1600, 1600);
    Camera my_camera(16, 16);

    shared_ptr<Corner> a = make_shared<Corner>(Point(0, 0, 0));
    shared_ptr<Corner> b = make_shared<Corner>(Point(7, 3, 0));
    shared_ptr<Corner> c = make_shared<Corner>(Point(2, 5, 0));
    shared_ptr<Corner> d = make_shared<Corner>(Point(0, 0, 3));

    a->set_color(Color(255, 0, 0));
    b->set_color(Color(0, 255, 0));
    c->set_color(Color(0, 0, 255));
    d->set_color(Color(255, 255, 255));

    Face A(a, b, c);
    Face B(a, b, d);
    Face C(a, d, c);
    Face D(d, b, c);

    cout << A.to_string() << endl;

    my_camera.render(my_window.get_screen(), A);

    my_camera.move(Point(7, 3, 0));

    my_window.get_screen().flush();

    my_camera.render(my_window.get_screen(), A);

    my_window.refresh();

    double rot = 0;

    while(my_window.is_open()){
        my_camera.rotate(Point(rot, 0, 0));
        my_camera.render(my_window.get_screen(), A);
        my_camera.render(my_window.get_screen(), B);
        my_camera.render(my_window.get_screen(), C);
        my_camera.render(my_window.get_screen(), D);
        my_window.refresh();
        my_window.get_screen().flush();
        my_window.check_event();
        rot++;
    }

    return 0;
}