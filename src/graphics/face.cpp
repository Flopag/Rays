#include "graphics/face.hpp"

using namespace graphics;

string Face::to_string() const {
    using std::to_string;
    string output_string = "Points:\n";

    for(shared_ptr<Point_3D> point : this->points)
        output_string += point->to_string() + "\n";

    return output_string;
}