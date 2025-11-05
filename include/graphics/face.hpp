#ifndef G_FACE_HPP
#define G_FACE_HPP

#include <vector>
#include <iostream>
#include <string>
#include <memory>

#include <os_api/screen.hpp>
#include "point.hpp"
#include "color.hpp"

using namespace std;
using namespace os_api;

namespace graphics {

    class Face{
        private:
            vector<shared_ptr<Point>> points;

            // Cache
            vector<Point> cached_projections;
            vector<Color> cached_point_colors;
            double cached_barycentrif_deno_beta=0;
            double cached_barycentrif_deno_gamma=0;
            double cached_a_beta=0, cached_b_beta=0, cached_c_beta=0;
            double cached_a_gamma=0, cached_b_gamma=0, cached_c_gamma=0;
            bool has_cache = false;
        
        public:
            Face(shared_ptr<Point> a, shared_ptr<Point> b, shared_ptr<Point> c) {
                this->points.push_back(a);
                this->points.push_back(b);
                this->points.push_back(c);

                this->cached_projections.push_back(Point());
                this->cached_projections.push_back(Point());
                this->cached_projections.push_back(Point());

                this->cached_point_colors.push_back(a->get_color());
                this->cached_point_colors.push_back(b->get_color());
                this->cached_point_colors.push_back(c->get_color());
            };

            string to_string() const;
            Face& update_projection(const Point& origin, const Point& rotations);
            Color get_color(const Point& location) const;

            Point get_projection_max() const;
            Point get_projection_min() const;

            vector<shared_ptr<Point>> get_points() {
                return points;
            };
    };

}

#endif