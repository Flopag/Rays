#include <cmath>
#include "graphics/face.hpp"

using namespace graphics;

string Face::to_string() const {
    using std::to_string;
    string output_string = "Points:\n";

    for(shared_ptr<Point_3D> point : this->points)
        output_string += point->to_string() + "\n";

    return output_string;
}

// from: https://courses.cms.caltech.edu/cs171/assignments/hw2/hw2-notes/notes-hw2.html
double inline barycentrif_function(const Point_3D p, const Point_3D i, const Point_3D j){
    return (i.get_y() - j.get_y()) * p.get_x() + (j.get_x() - i.get_x()) * p.get_y() + i.get_x() * j.get_y() - j.get_x() * i.get_y();
}

Color Face::get_color(const Point_3D& origin, const Point_3D& rotations, const Point_2D& location) {
    if(!(origin == this->prev_origin && rotations == this->prev_rotations) || !this->has_cache) {
        this->prev_origin = origin;
        this->prev_rotations = rotations;
        
        this->cached_projections[0] = this->points[0]->rebased(origin, rotations);
        this->cached_projections[1] = this->points[1]->rebased(origin, rotations);
        this->cached_projections[2] = this->points[2]->rebased(origin, rotations);

        this->has_cache = true;
    }

    Point_3D a = this->cached_projections[0];
    Point_3D b = this->cached_projections[1];
    Point_3D c = this->cached_projections[2];
    Point_3D location_3D = Point_3D(location);

    double beta = barycentrif_function(location_3D, b, c) / barycentrif_function(a, b, c);
    double gamma = barycentrif_function(location_3D, a, c) / barycentrif_function(b, a, c);
    double alpha = 1 - beta - gamma;

    if(alpha >= 0 && alpha <= 1 && beta >= 0 && beta <= 1 && gamma >= 0 && gamma <= 1)
        return Color(255, 255, 255);

    return Color();
}