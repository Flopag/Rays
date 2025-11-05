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

Window& Window::check_event() {
    this->window.pollEvent();
    return *this;
}

bool Window::is_open() const {
    return this->window.isOpen();
}

Window& Window::close() {
    this->window.close();
    return *this;
}

Window& Window::open() {
    this->window = sf::RenderWindow(sf::VideoMode({(uint) this->width, (uint) this->height}), "rays", sf::Style::None);
    this->window.setPosition({0, 0});
    return *this;
}