#include <stdexcept>
#include <iostream>
#include "screen/color_screen.hpp"

using namespace screen;

Color_screen& Color_screen::set_pixel(size_t i, size_t j, uint8_t red, uint8_t green, uint8_t blue) {
    if(i >= this->width || j >= this->height || i < 0 || j < 0)
        return *this;

    this->image.setPixel(sf::Vector2u(i, j), sf::Color(red, green, blue));

    return *this;
}

Color_screen& Color_screen::flush() {
    this->image = sf::Image({(uint) this->width, (uint) this->height}, BACKGROUND_COLOR);
    
    return *this;
}

void Color_screen::show() {
    sf::Texture texture(this->image);
    sf::Sprite sprite(texture);
    this->window.draw(sprite);
    this->window.display();
}

string Color_screen::to_string() const {
    using std::to_string;
    return "The width is " + to_string(this->width) + " and the height is " + to_string(this->height);
}