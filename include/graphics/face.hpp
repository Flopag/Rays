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
            vector<shared_ptr<Point_3D>> points;

            vector<Point_3D> cached_projections;
            Point_3D prev_origin, prev_rotations;
            bool has_cache = false;
        
        public:
            Face(shared_ptr<Point_3D> a, shared_ptr<Point_3D> b, shared_ptr<Point_3D> c) {
                this->points.push_back(a);
                this->points.push_back(b);
                this->points.push_back(c);

                this->cached_projections.push_back(Point_3D());
                this->cached_projections.push_back(Point_3D());
                this->cached_projections.push_back(Point_3D());
            };

            string to_string() const;
            Color get_color(const Point_3D& origin, const Point_3D& rotations, const Point_2D& location);

            vector<shared_ptr<Point_3D>> get_points() {
                return points;
            };
    };

}

#endif