#include <cmath>
#include <iostream>
#include "sphere.hpp"

Sphere::Sphere():
    midpoint_{glm::vec3()}, radius_{0}
    {}

Sphere::Sphere(glm::vec3 const& midpoint, float radius):
    midpoint_{midpoint}, radius_{radius}
    {
        if (radius < 0){
            std::cout << "Error: recevied radius smaller than 0 for sphere";
            exit(-1);
        }
    }

float Sphere::area() const{
    return 4 * M_PI * (radius_ * radius_);
}

float Sphere::volume() const{
    return (4.0f/3.0f) * M_PI * (radius_ * radius_ * radius_);
}