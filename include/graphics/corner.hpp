#ifndef G_CORNER_HPP
#define G_CORNER_HPP

#include <string>
#include "point.hpp"
#include "color.hpp"

using namespace std;

namespace graphics {

    class Corner{
        private:
            Point position = Point(0, 0, 0);
            Color color = Color(255, 255, 255);
        
        public:
            Corner(){};
            Corner(Point position) : position(position) {};

            Corner& move(Point new_position);
            Corner& set_color(Color new_color);

            string to_string() const;

            Point get_position() const {return this->position;};
            Color get_color() const {return this->color;};
    };

}

#endif