#ifndef G_POINT_HPP
#define G_POINT_HPP

#include <string>

using namespace std;

namespace graphics {

    class Point_2D;

    class Point_3D{
        private:
            double x, y, z;
        
        public:
            Point_3D(double x, double y, double z) : x(x), y(y), z(z) {};
            Point_3D(const Point_3D& point) : x(point.get_x()), y(point.get_y()), z(point.get_z()) {};

            Point_3D& move(double x, double y, double z);

            Point_2D projection(Point_3D origin, Point_3D rotations) const;
            string to_string() const;

            double get_x() const {return this->x;};
            double get_y() const {return this->y;};
            double get_z() const {return this->z;};
    };

    class Point_2D{
        private:
            double x, y;
        
        public:
            Point_2D(double x, double y) : x(x), y(y) {};

            Point_2D& move(double x, double y);

            string to_string() const;

            double get_x() const {return this->x;};
            double get_y() const {return this->y;};
    };

}

#endif