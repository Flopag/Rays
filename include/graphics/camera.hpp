#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "./point.hpp"
#include "./face.hpp"

namespace graphics {

    class Camera {
        private:
            Point position = Point(0, 0, 0);
            Point rotation = Point(0, 0, 0);
            size_t width=0, height=0;

        public:
            Camera(int height, int width) : width(width), height(height) {
                if(width < 0 || height < 0)
                    throw runtime_error("The camera must have positive values as size");
                if(width == 0 || height == 0){
                    width = 0;
                    this->height = 0;
                }
            };

            Camera& move(Point new_position);
            Camera& rotate(Point new_rotation);

            const Camera& render(Screen& screen, Face face) const;
    };

}

#endif