#define _USE_MATH_DEFINES

#include <cmath>
#include <iostream>
#include "graphics/point.hpp"

using namespace graphics;

Point& Point::move(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;

    return *this;
}

Point Point::rebased(Point origin, Point rotations) const {
    Point rebased_point(*this);
    /* Centering */
    rebased_point.move(
        rebased_point.get_x() - origin.get_x(),
        rebased_point.get_y() - origin.get_y(),
        rebased_point.get_z() - origin.get_z()
    );

    /* Rotating */
    double angle;
    // z rotation
    angle = rotations.get_z() * (M_PI / 180);

    rebased_point.move(
        rebased_point.get_x() * cos(angle) - rebased_point.get_y() * sin(angle),
        rebased_point.get_x() * sin(angle) + rebased_point.get_y() * cos(angle),
        rebased_point.get_z()
    );

    // x rotation
    angle = rotations.get_x() * (M_PI / 180);

    rebased_point.move(
        rebased_point.get_x(),
        rebased_point.get_y() * cos(angle) - rebased_point.get_z() * sin(angle),
        rebased_point.get_y() * sin(angle) + rebased_point.get_z() * cos(angle)
    );

    // y rotation
    angle = rotations.get_y() * (M_PI / 180);

    rebased_point.move(
        rebased_point.get_z() * sin(angle) + rebased_point.get_x() * cos(angle),
        rebased_point.get_y(),
        rebased_point.get_z() * cos(angle) - rebased_point.get_x() * sin(angle)
    );

    return rebased_point;
}

Point Point::projection(Point origin, Point rotations) const {
    Point rebased_point = this->rebased(origin, rotations);

    Point projected_point(rebased_point.get_x(), rebased_point.get_y());

    return projected_point;
}

Point& Point::set_color(Color new_color) {
    this->color = new_color; 
    return *this;
}

string Point::to_string() const {
    using std::to_string;
    return "(" + to_string(this->x) + ", " + to_string(this->y) + ", " + to_string(this->z) + ")";
}