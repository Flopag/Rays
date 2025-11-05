#ifndef G_POINT_HPP
#define G_POINT_HPP

#include <string>
#include "color.hpp"

using namespace std;

namespace graphics {

    class Point{
        private:
            double x=0, y=0, z=0;
            Color color = Color(255, 255, 255);
        
        public:
            Point(){};
            Point(double x, double y, double z=0) : x(x), y(y), z(z) {};

            Point& move(double x, double y, double z=0);

            Point projection(Point origin, Point rotations) const;
            Point rebased(Point origin, Point rotations) const;
            string to_string() const;
            Point& set_color(Color new_color);

            double get_x() const {return this->x;};
            double get_y() const {return this->y;};
            double get_z() const {return this->z;};
            Color get_color() const {return this->color;};

            bool operator==(const Point& other) const {
                return this->get_x() == other.get_x() 
                    && this->get_y() == other.get_y() 
                    && this->get_z() == other.get_z();
            };
    };

}

#endif