#ifndef G_FACE_HPP
#define G_FACE_HPP

#include <vector>
#include <iostream>
#include <string>
#include <memory>
#include "graphics/point.hpp"

using namespace std;

namespace graphics {

    class Face{
        private:
            vector<shared_ptr<Point_3D>> points;
        
        public:
            Face(shared_ptr<Point_3D> a, shared_ptr<Point_3D> b, shared_ptr<Point_3D> c) {
                this->points.push_back(a);
                this->points.push_back(b);
                this->points.push_back(c);
            };

            string to_string() const;

            vector<shared_ptr<Point_3D>> get_points() {
                return points;
            };
    };

}

#endif