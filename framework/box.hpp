#ifndef BOX_HPP
#define BOX_HPP
#include <glm/vec3.hpp>
#include "shape.hpp"

class Box: public Shape{

    public:

        Box();

        Box(glm::vec3 const& axis_aligned_min, glm::vec3 const& axis_aligned_max);

        Box(glm::vec3 const& axis_aligned_min, glm::vec3 const& axis_aligned_max, std::string const& name,
                Color const& color);

        float area() const override;

        float volume() const override;


    private:

        glm::vec3 axis_aligned_min_;
        glm::vec3 axis_aligned_max_;

};

#endif