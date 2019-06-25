#include "box.hpp"

Box::Box():
    axis_aligned_min_{glm::vec3{}}, axis_aligned_max_{glm::vec3{}}
    {}

Box::Box(glm::vec3 const& axis_aligned_min, glm::vec3 const& axis_aligned_max):
    axis_aligned_min_{axis_aligned_min}, axis_aligned_max_{axis_aligned_max}
    {}

float Box::area() const{
    return 4 * (abs(axis_aligned_min_.x - axis_aligned_max_.x)) * (abs(axis_aligned_min_.z - axis_aligned_max_.z))
           + 2 * (abs(abs(axis_aligned_min_.y) - abs(axis_aligned_max_.y))) * (abs(axis_aligned_min_.z - axis_aligned_max_.z));
}

float Box::volume() const{
    return (abs(axis_aligned_min_.x - axis_aligned_max_.x))
           * (abs(axis_aligned_min_.y - axis_aligned_max_.y))
           * (abs(axis_aligned_min_.z - axis_aligned_max_.z));
}
