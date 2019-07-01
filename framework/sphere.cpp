#include <cmath>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtx/intersect.hpp>
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

Sphere::Sphere(glm::vec3 const& midpoint, float radius, std::string const& name, Color const& color):
    midpoint_{midpoint}, radius_{radius}
    {
        name_ = name;
        color_ = color;
        std::cout << "sphere con \n";
    }

Sphere::~Sphere(){
    std::cout << "sphere des \n";
}    

float Sphere::area() const{
    return 4 * M_PI * (radius_ * radius_);
}

float Sphere::volume() const{
    return (4.0f/3.0f) * M_PI * (radius_ * radius_ * radius_);
}

std::ostream& Sphere::print(std::ostream& os) const {
    os << "name of sphere: " << name_ << "\n" << "position: " << midpoint_.x << "/" << midpoint_.y << "/" <<
    midpoint_.z << "  radius: " << radius_ << "\ncolor(RGB%): " << color_.r << "|" << color_.g << "|" << color_.b << "\n" <<
    "area: " << area() << " volume: " << volume() << "\n";
    return os;
}

HitPoint Sphere::intersect(Ray const& ray) const{
    float distance = 0.0f;
    glm::vec3 direction = glm::normalize(ray.direction);
    bool hit = glm::intersectRaySphere(ray.origin, ray.direction, midpoint_, radius_, distance);
    if (hit){
        float hit_x = ray.origin.x + distance * direction.x;
        float hit_y = ray.origin.y + distance * direction.y;
        float hit_z = ray.origin.z + distance * direction.z;
        glm::vec3 point_of_hit{hit_x, hit_y, hit_z};
        HitPoint hitpoint = HitPoint{hit, distance, name_, color_, point_of_hit, direction};
        return hitpoint;
    } else{
        HitPoint hitpoint;
        return hitpoint;
    }
}