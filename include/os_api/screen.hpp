#ifndef COLOR_SCREEN_HPP
#define COLOR_SCREEN_HPP

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

#include "./screen.hpp"

using namespace std;

namespace os_api {

    class Screen{
        private:
            size_t width, height;
            sf::Image image;
            sf::RenderWindow window;
            sf::Color background_color = sf::Color::Black;
        
        public:
            Screen(int width, int height) : width(width), height(height) {
                if(width < 0 || height < 0)
                    throw runtime_error("The screen must have positive values as size");
                if(width == 0 || height == 0){
                    width = 0;
                    this->height = 0;
                }
                this->window = sf::RenderWindow(sf::VideoMode({(uint) width, (uint) height}), "rays");
                this->image = sf::Image({(uint) width, (uint) height}, this->background_color);
            };

            Screen& set_pixel(size_t i, size_t j, uint8_t red, uint8_t green, uint8_t blue);
            Screen& flush();

            void show();
            string to_string() const;
    };

}

#endif