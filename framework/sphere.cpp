#include <cmath>
#include <iostream>
#include "sphere.hpp"

Sphere::Sphere():
    midpoint_{glm::vec3()}, radius_{0}
    {
        color_ = Color{0.5f, 0.5f, 0.5f};
        name_ = "";
    }

Sphere::Sphere(glm::vec3 const& midpoint, float radius):
    midpoint_{midpoint}, radius_{radius}
    {
        if (radius < 0){
            std::cout << "Error: recevied radius smaller than 0 for sphere";
            exit(-1);
        }
        color_ = Color{0.5f, 0.5f, 0.5f};
        name_ = "";
    }

Sphere::Sphere(glm::vec3 const &midpoint, float radius, std::string const &name, Color const &color):
    midpoint_{midpoint}, radius_{radius}
    {
        name_ = name;
        color_ = color;
    }

float Sphere::area() const{
    return 4 * M_PI * (radius_ * radius_);
}

float Sphere::volume() const{
    return (4.0f/3.0f) * M_PI * (radius_ * radius_ * radius_);
}