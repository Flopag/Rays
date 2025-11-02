#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SFML/Graphics.hpp>

#include "./screen.hpp"

using namespace std;

namespace os_api {

    class Window{
        private:
            size_t width, height;
            sf::RenderWindow window;
            Screen screen;
        
        public:
            Window(int width, int height) : width(width), height(height) {
                if(width < 0 || height < 0)
                    throw runtime_error("The window must have positive values as size");
                if(width == 0 || height == 0){
                    width = 0;
                    this->height = 0;
                }
                this->window = sf::RenderWindow(sf::VideoMode({(uint) height, (uint) width}), "rays");
                this->screen = Screen(width, height);
            };
            
            Screen& get_screen();
            Window& refresh();
    };

}

#endif