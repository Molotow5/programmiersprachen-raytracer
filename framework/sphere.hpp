#ifndef SPHERE_HPP
#define SPHERE_HPP
#include <glm/vec3.hpp>
#include "shape.hpp"


class Sphere: public Shape{

    public:

        Sphere();

        Sphere(glm::vec3 const& midpoint, float radius);

        float area() const override;

        float volume() const override;


    private:

        glm::vec3 midpoint_;
        float radius_;

};

#endif 