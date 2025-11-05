#ifndef COLOR_HPP
#define COLOR_HPP

#include <string>
#include <cstdint>

using namespace std;

namespace graphics {

    class Color {
        private:
            uint8_t red = 0, green = 0, blue = 0;
            uint8_t alpha = 0;

        public:
            Color(){};
            Color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha=255) : red(red), green(green), blue(blue), alpha(alpha) {};

            uint8_t get_red() const {return this->red;};
            uint8_t get_green() const {return this->green;};
            uint8_t get_blue() const {return this->blue;};
            uint8_t get_alpha() const {return this->alpha;};

            string to_string() const {
                using std::to_string;
                return "(" 
                    + to_string(this->get_red()) + ", "
                    + to_string(this->get_green()) + ", "
                    + to_string(this->get_blue()) + ", "
                    + to_string(this->get_alpha()) + ")";
                };
    };
}

#endif