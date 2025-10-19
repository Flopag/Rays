#include <cmath>
#include "face.hpp"

using namespace graphics;

string Face::to_string() const {
    using std::to_string;
    string output_string = "Points:\n";

    for(shared_ptr<Point_3D> point : this->points)
        output_string += point->to_string() + "\n";

    return output_string;
}

// from: https://courses.cms.caltech.edu/cs171/assignments/hw2/hw2-notes/notes-hw2.html
double inline barycentrif_function(Point_2D p, Point_2D i, Point_2D j){
    return (i.get_y() - j.get_y()) * p.get_x() + (j.get_x() - i.get_x()) * p.get_y() + i.get_x() * j.get_y() - j.get_x() * i.get_y();
}

void Face::render(Screen& screen, Point_3D origin, Point_3D rotations, Point_3D offset) const {
    Point_2D a = this->points[0]->projection(origin, rotations);
    Point_2D b = this->points[1]->projection(origin, rotations);
    Point_2D c = this->points[2]->projection(origin, rotations);

    // Use of triangle interpolation
    // from: https://courses.cms.caltech.edu/cs171/assignments/hw2/hw2-notes/notes-hw2.html

    double x_min = min(a.get_x(), min(b.get_x(), c.get_x()));
    double x_max = max(a.get_x(), max(b.get_x(), c.get_x()));
    double y_min = min(a.get_y(), min(b.get_y(), c.get_y()));
    double y_max = max(a.get_y(), max(b.get_y(), c.get_y()));

    for(int i = round(y_min); i<round(y_max); ++i){
        for(int j = round(x_min); j<round(x_max); ++j){
            double beta = barycentrif_function(Point_2D(j, i), b, c) / barycentrif_function(a, b, c);
            double gamma = barycentrif_function(Point_2D(j, i), a, c) / barycentrif_function(b, a, c);
            double alpha = 1 - beta - gamma;

            if(alpha >= 0 && alpha <= 1 && beta >= 0 && beta <= 1 && gamma >= 0 && gamma <= 1)
                screen.set_pixel(i+offset.get_y(), j+offset.get_x(), true);
        }
    }
}