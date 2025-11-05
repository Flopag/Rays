#include <cmath>
#include<bits/stdc++.h> 
#include "graphics/face.hpp"

using namespace graphics;

string Face::to_string() const {
    using std::to_string;
    string output_string = "Points:\n";

    for(shared_ptr<Point> point : this->points)
        output_string += point->to_string() + "\n";

    return output_string;
}

// from: https://courses.cms.caltech.edu/cs171/assignments/hw2/hw2-notes/notes-hw2.html
double inline barycentrif_function(const Point& p, const Point& i, const Point& j){
    return (i.get_y() - j.get_y()) * p.get_x() + (j.get_x() - i.get_x()) * p.get_y() + i.get_x() * j.get_y() - j.get_x() * i.get_y();
}

double inline optimized_barycentrif_function(const Point& p, const double a, const double b, const double c){
    return a * p.get_x() + b * p.get_y() + c;
}

Face& Face::update_projection(const Point& origin, const Point& rotations) {    
    this->cached_projections[0] = this->points[0]->rebased(origin, rotations);
    this->cached_projections[1] = this->points[1]->rebased(origin, rotations);
    this->cached_projections[2] = this->points[2]->rebased(origin, rotations);

    this->cached_point_colors[0] = this->points[0]->get_color();
    this->cached_point_colors[1] = this->points[1]->get_color();
    this->cached_point_colors[2] = this->points[2]->get_color();

    Point a = this->cached_projections[0];
    Point b = this->cached_projections[1];
    Point c = this->cached_projections[2];

    this->cached_barycentrif_deno_beta = barycentrif_function(a, b, c);
    this->cached_barycentrif_deno_gamma = barycentrif_function(b, a, c);
    this->cached_a_beta = (b.get_y() - c.get_y());
    this->cached_b_beta = (c.get_x() - b.get_x());
    this->cached_c_beta = b.get_x() * c.get_y() - c.get_x() * b.get_y();
    this->cached_a_gamma = (a.get_y() - c.get_y());
    this->cached_b_gamma = (c.get_x() - a.get_x());
    this->cached_c_gamma = a.get_x() * c.get_y() - c.get_x() * a.get_y();

    this->has_cache = true;

    return *this;
}

Color inline get_barycentrif_color(const Color& a, const Color& b, const Color& c, const double& alpha, const double& beta, const double& gamma){
    return Color(
        alpha*a.get_red() + beta*b.get_red() + gamma*c.get_red(),
        alpha*a.get_green() + beta*b.get_green() + gamma*c.get_green(),
        alpha*a.get_blue() + beta*b.get_blue() + gamma*c.get_blue()
    );
}

Color Face::get_color(const Point& location) const {
    if(!this->has_cache)
        return Color();

    double beta = optimized_barycentrif_function(location, cached_a_beta, cached_b_beta, cached_c_beta) / this->cached_barycentrif_deno_beta;
    if(beta >= 0 && beta <= 1){
        double gamma = optimized_barycentrif_function(location, cached_a_gamma, cached_b_gamma, cached_c_gamma) / this->cached_barycentrif_deno_gamma;
        if(gamma >= 0 && gamma <= 1){
            double alpha = 1 - beta - gamma;
            if(alpha > 0){
                const Color& a = this->cached_point_colors[0];
                const Color& b = this->cached_point_colors[1];
                const Color& c = this->cached_point_colors[2];
                return get_barycentrif_color(a, b, c, alpha, beta, gamma);
            }
        }
    }

    return Color();
}

Point Face::get_projection_max() const {
    double max_x = max({
        this->cached_projections[0].get_x(), 
        this->cached_projections[1].get_x(), 
        this->cached_projections[2].get_x()
    });
    double max_y = max({
        this->cached_projections[0].get_y(), 
        this->cached_projections[1].get_y(), 
        this->cached_projections[2].get_y()
    });
    double max_z = max({
        this->cached_projections[0].get_z(), 
        this->cached_projections[1].get_z(), 
        this->cached_projections[2].get_z()
    });

    return Point(max_x, max_y, max_z);
}

Point Face::get_projection_min() const {
    double min_x = min({
        this->cached_projections[0].get_x(), 
        this->cached_projections[1].get_x(), 
        this->cached_projections[2].get_x()
    });
    double min_y = min({
        this->cached_projections[0].get_y(), 
        this->cached_projections[1].get_y(), 
        this->cached_projections[2].get_y()
    });
    double min_z = min({
        this->cached_projections[0].get_z(), 
        this->cached_projections[1].get_z(), 
        this->cached_projections[2].get_z()
    });

    return Point(min_x, min_y, min_z);
}
