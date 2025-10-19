#include <stdexcept>
#include <iostream>
#include "screen/screen.hpp"

#define COORD(i, j) j*this->width+i

using namespace screen;

Screen& Screen::set_pixel(size_t i, size_t j, bool value) {
    if(i >= this->width || j >= this->height || i < 0 || j < 0)
        return *this;

    this->bw_pixels[COORD(i, j)] = value;

    return *this;
}

Screen& Screen::flush() {
    for(size_t j=0; j < this->height; ++j)
        for(size_t i=0; i < this->width; ++i)
            this->bw_pixels[COORD(i, j)] = false;
    
    return *this;
}

void Screen::show() const {
    cout << this->to_string() << endl;
}

string Screen::to_string() const {
    string output_string = "";

    for(size_t j=0; j < this->height; ++j){
        for(size_t i=0; i < this->width; ++i){
            if(this->bw_pixels[COORD(i, j)])
                output_string += "■ ";
            else
                output_string += "□ ";
        }

        output_string += "\n";
    }

    return output_string;
}