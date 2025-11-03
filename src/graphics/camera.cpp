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
    #define TO_I(value) (value+offset_height)/pixel_height
    #define TO_J(value) (value+offset_width)/pixel_width
    face.update_projection(this->position, this->rotation);
    const size_t screen_width=screen.get_width(), screen_height=screen.get_height();
    const double pixel_width=(this->width/(double)screen_width), pixel_height=(this->height/(double)screen_height);
    const double offset_width=this->width/2.0, offset_height=this->height/2.0;

    Point receptacle;
    Point max = face.get_projection_max();
    Point min = face.get_projection_min();

    size_t min_i = (TO_I(min.get_x()) > 0) ? TO_I(min.get_x()) : 0;
    size_t min_j = (TO_J(min.get_y()) > 0) ? TO_J(min.get_y()) : 0;
    size_t max_i = (TO_I(max.get_x()) < screen_height) ? TO_I(max.get_x()) : screen_height;
    size_t max_j = (TO_J(max.get_y()) < screen_width) ? TO_J(max.get_y()) : screen_width;

    for(size_t i=min_i; i<max_i; ++i){
        for(size_t j=min_j; j<max_j; ++j){
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