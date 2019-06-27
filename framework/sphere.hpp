#ifndef SPHERE_HPP
#define SPHERE_HPP
#include <glm/vec3.hpp>
#include "shape.hpp"


class Sphere: public Shape{

    public:

        Sphere();

        Sphere(glm::vec3 const& midpoint, float radius);

        Sphere(glm::vec3 const& midpoint, float radius, std::string const& name, Color const& color);

        float area() const override;

        float volume() const override;

        std::ostream& print(std::ostream& os) const override ;

    private:

        glm::vec3 midpoint_;
        float radius_;

};

#endif 