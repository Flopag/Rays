#include <stdexcept>
#include <iostream>
#include "screen/screen.hpp"

#define coord(i, j) j*this->width+i

using namespace screen;

Screen& Screen::set_pixel(size_t i, size_t j, bool value) {
    if(i >= this->width || j >= this->height)
        throw runtime_error("coordinate out of range");

    this->bw_pixels[coord(i, j)] = value;

    return *this;
}

Screen& Screen::flush() {
    for(size_t j=0; j < this->height; ++j)
        for(size_t i=0; i < this->width; ++i)
            this->bw_pixels[coord(i, j)] = false;
    
    return *this;
}

void Screen::show() {
    cout << this->to_string() << endl;
}

string Screen::to_string() {
    string output_string = "";

    for(size_t j=0; j < this->height; ++j){
        for(size_t i=0; i < this->width; ++i){
            if(this->bw_pixels[coord(i, j)])
                output_string += "■ ";
            else
                output_string += "□ ";
        }

        output_string += "\n";
    }

    return output_string;
}