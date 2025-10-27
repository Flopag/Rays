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

shared_ptr<sf::Texture> Screen::get_texture() const {
    shared_ptr<sf::Texture> texture = make_shared<sf::Texture>(this->image);
    return texture;
}