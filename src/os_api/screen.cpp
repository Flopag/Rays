#include <stdexcept>
#include <iostream>
#include "os_api/screen.hpp"

using namespace os_api;

Screen& Screen::set_pixel(size_t i, size_t j, uint8_t red, uint8_t green, uint8_t blue) {
    if(i >= this->width || j >= this->height || i < 0 || j < 0)
        return *this;

    this->image.setPixel(sf::Vector2u(i, j), sf::Color(red, green, blue));

    return *this;
}

Screen& Screen::flush() {
    this->image = sf::Image({(uint) this->width, (uint) this->height}, this->background_color);
    
    return *this;
}

void Screen::show() {
    sf::Texture texture(this->image);
    sf::Sprite sprite(texture);
    this->window.draw(sprite);
    this->window.display();
}

string Screen::to_string() const {
    using std::to_string;
    return "The width is " + to_string(this->width) + " and the height is " + to_string(this->height);
}