#include "graphics/camera.hpp"
#include "graphics/color.hpp"

using namespace graphics;

const Camera& Camera::render(Screen& screen, Face face) const {
    const size_t screen_width=screen.get_width(), screen_height=screen.get_height();
    const double pixel_width=(this->width/screen_width), pixel_height=(this->height/screen_height);
    const double offset_width=this->width/2, offset_height=this->height/2; 

    for(size_t i=0; i<screen_width; ++i){
        for(size_t j=0; j<screen_height; ++j){
            const Point_2D current_position = 
            Point_2D(
                this->position.get_x() + pixel_width*i - offset_width, 
                this->position.get_y() + pixel_height*j - offset_height
            );
            const Color current_color = face.get_color(this->position, this->rotation, current_position);
            if(current_color.get_alpha() != 0)
                screen.set_pixel(i, j, current_color.get_red(), current_color.get_green(), current_color.get_blue());
        }
    }

    return *this;
}