#ifndef SCREEN_HPP
#define SCREEN_HPP

#include <string>
#include <SFML/Graphics.hpp>

using namespace std;

namespace os_api {

    class Screen{
        private:
            size_t width, height;
            sf::Image image;
            sf::Color background_color = sf::Color::Black;

        public:
            Screen() : width(0), height(0) {
                this->image = sf::Image();
            };
            Screen(int width, int height) : width(width), height(height) {
                if(width < 0 || height < 0)
                    throw runtime_error("The screen must have positive values as size");
                if(width == 0 || height == 0){
                    width = 0;
                    this->height = 0;
                }
                this->image = sf::Image({(uint) width, (uint) height}, this->background_color);
            };

            Screen& set_pixel(size_t i, size_t j, uint8_t red, uint8_t green, uint8_t blue);
            Screen& flush();

            shared_ptr<sf::Texture> get_texture() const;
            size_t get_width() const {return this->width;};
            size_t get_height() const {return this->height;};
    };

}

#endif