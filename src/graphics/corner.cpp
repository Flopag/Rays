#include "graphics/corner.hpp"

using namespace graphics;

Corner& Corner::move(Point new_position) {
    this->position = new_position;

    return *this;
}

Corner& Corner::set_color(Color new_color) {
    this->color = new_color; 
    return *this;
}

string Corner::to_string() const {
    return this->position.to_string() + this->color.to_string();
}