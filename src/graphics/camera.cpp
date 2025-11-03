#include "graphics/camera.hpp"
#include "graphics/color.hpp"

using namespace graphics;

Camera& Camera::move(Point new_position) {
    this->position = new_position;

    return *this;
}

Camera& Camera::rotate(Point new_rotation) {
    this->rotation = new_rotation;
    
    return *this;
}

const Camera& Camera::render(Screen& screen, Face face) const {
    face.update_projection(this->position, this->rotation);
    const size_t screen_width=screen.get_width(), screen_height=screen.get_height();
    const double pixel_width=(this->width/(double)screen_width), pixel_height=(this->height/(double)screen_height);
    const double offset_width=this->width/2.0, offset_height=this->height/2.0;

    Point receptacle;

    for(size_t i=0; i<screen_height; ++i){
        for(size_t j=0; j<screen_width; ++j){
            receptacle.move(
                pixel_height*i - offset_height, 
                pixel_width*j - offset_width
            );
            const Color current_color = face.get_color(receptacle);
            if(current_color.get_alpha() != 0)
                screen.set_pixel(i, j, current_color.get_red(), current_color.get_green(), current_color.get_blue());
        }
    }

    return *this;
}