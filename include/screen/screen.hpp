#ifndef SCREEN_HPP
#define SCREEN_HPP

#include <vector>
#include <string>

using namespace std;

namespace screen {

    class Screen{
        private:
            size_t width, height;
            vector<bool> bw_pixels;
        
        public:
            Screen(int width, int height) : width(width), height(height) {
                if(width < 0 || height < 0)
                    throw runtime_error("The screen must have positive values as size");
                bw_pixels = vector<bool>(width*height, false);
                if(width == 0 || height == 0){
                    width = 0;
                    this->height = 0;
                }
            };

            Screen& set_pixel(size_t i, size_t j, bool value);
            Screen& flush();

            void show() const;
            string to_string() const;
    };

}

#endif