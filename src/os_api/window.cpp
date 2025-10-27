#include <stdexcept>
#include <iostream>
#include "os_api/window.hpp"

using namespace os_api;

Screen& Window::get_screen() {
    return this->screen;
}

Window& Window::refresh() {
    shared_ptr<sf::Texture> texture = this->screen.get_texture();
    sf::Sprite sprite(*texture);
    this->window.draw(sprite);
    this->window.display();

    return *this;
}