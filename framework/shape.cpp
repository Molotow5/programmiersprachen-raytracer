#include "shape.hpp"

Shape::Shape():
    name_{""}, color_{Color{0.5f, 0.5f, 0.5f}}
    {std::cout << "shape con \n";}

Shape::Shape(std::string const &name, Color const &color):
    name_{name}, color_{color}
    {std::cout << "shape con \n";}

Shape::~Shape(){
    std::cout << "shape des \n";
}

std::ostream& operator<<(std::ostream& os, Shape const& s){
    return s.print(os);
}