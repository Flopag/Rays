#include "graphics/camera.hpp"
#include "graphics/color.hpp"

using namespace graphics;

Camera& Camera::move(Point_3D new_position) {
    this->position = new_position;

    return *this;
}

Camera& Camera::rotate(Point_3D new_rotation) {
    this->rotation = new_rotation;
    
    return *this;
}

const Camera& Camera::render(Screen& screen, Face face) const {
    const size_t screen_width=screen.get_width(), screen_height=screen.get_height();
    const double pixel_width=(this->width/(double)screen_width), pixel_height=(this->height/(double)screen_height);
    const double offset_width=this->width/2.0, offset_height=this->height/2.0;

    Point_2D receptacle;

    for(size_t i=0; i<screen_width; ++i){
        for(size_t j=0; j<screen_height; ++j){
            const Point_2D current_position = 
            receptacle.move(
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