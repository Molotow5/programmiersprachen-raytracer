#ifndef HITPOINT_HPP
#define HITPOINT_HPP
#include <string>
#include <glm/vec3.hpp>
#include "color.hpp"

struct HitPoint{
    
    bool hit = false;
    float distance_to_hit = 0;
    std::string name_of_hit = "";
    Color color_of_hit = Color{0.0f, 0.0f, 0.0f};
    glm::vec3 point_of_hit = glm::vec3{0.0f, 0.0f, 0.0f};
    glm::vec3 direction_of_hit = glm::vec3{0.0f, 0.0f, 0.0f};

};




#endif