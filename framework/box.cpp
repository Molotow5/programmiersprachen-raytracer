#include <math.h>
#include "box.hpp"

Box::Box():
    axis_aligned_min_{glm::vec3{}}, axis_aligned_max_{glm::vec3{}}
    {}

Box::Box(glm::vec3 const& axis_aligned_min, glm::vec3 const& axis_aligned_max):
    axis_aligned_min_{axis_aligned_min}, axis_aligned_max_{axis_aligned_max}
    {}

Box::Box(glm::vec3 const& axis_aligned_min, glm::vec3 const& axis_aligned_max, std::string const& name,
     Color const& color):
    axis_aligned_min_{axis_aligned_min}, axis_aligned_max_{axis_aligned_max}
    {
        name_ = name;
        color_ = color_;
    }

float Box::area() const{
    return 4 * abs(axis_aligned_min_.x - axis_aligned_max_.x) * abs(axis_aligned_min_.z - axis_aligned_max_.z)
           + 2 * abs(axis_aligned_min_.y - axis_aligned_max_.y) * abs(axis_aligned_min_.z - axis_aligned_max_.z);
}

float Box::volume() const{
    return (abs(axis_aligned_min_.x - axis_aligned_max_.x))
           * (abs(axis_aligned_min_.y - axis_aligned_max_.y))
           * (abs(axis_aligned_min_.z - axis_aligned_max_.z));
}

std::ostream& Box::print(std::ostream &os) const{
    os << "name of box: " << name_ << "\n" << "point 1: " << axis_aligned_min_.x << "/" << axis_aligned_min_.y << "/" <<
    axis_aligned_min_.z << "  point 2: " << axis_aligned_max_.x << "/" << axis_aligned_max_.y << "/" <<
    axis_aligned_max_.z << "\ncolor(RGB%): " << color_.r << "|" << color_.g << "|" << color_.b << "\n" <<
    "area : " << area() << "  volume: " << volume();
    return os;
}