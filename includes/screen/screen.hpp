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
                Screen(size_t width, size_t height) : width(width), height(height), bw_pixels(width*height, false) {};

                Screen& set_pixel(size_t i, size_t j, bool value);
                Screen& flush();

                void show();
                string to_string();
    };

}

#endif