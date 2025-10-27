#ifndef G_FACE_HPP
#define G_FACE_HPP

#include <vector>
#include <iostream>
#include <string>
#include <memory>

#include <os_api/screen.hpp>
#include "point.hpp"

using namespace std;
using namespace os_api;

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
            void render(Screen& screen, Point_3D origin, Point_3D rotations, Point_3D offset) const;

            vector<shared_ptr<Point_3D>> get_points() {
                return points;
            };
    };

}

#endif