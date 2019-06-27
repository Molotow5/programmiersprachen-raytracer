#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <iostream>
#include "../framework/sphere.hpp"
#include "../framework/box.hpp"
#include "../framework/shape.hpp"


TEST_CASE("taste sphere for constructor and area", "[area,constructor,sphere]"){
  Sphere Testobjekt_1 = Sphere();
  REQUIRE(Testobjekt_1.area() == 0);
  Sphere Testobjekt_2 = Sphere(glm::vec3{5.0f, 5.0f, 5.0f}, 25.0f);
  REQUIRE(Testobjekt_2.area() == Approx(7853.98f));
}

TEST_CASE("member function volume taste sphere", "[volume,sphere]"){
  Sphere Testobjekt_3 = Sphere(glm::vec3{}, 5.0f);
  REQUIRE(Testobjekt_3.volume() == Approx(523.598));
  Sphere Testobjekt_3_halb = Sphere();
  REQUIRE(Testobjekt_3_halb.volume() == 0);
}

TEST_CASE("taste box for constructor and area", "[area,constructor, box]"){
  Box Testobjekt_3_vorhalb = Box();
  REQUIRE(Testobjekt_3_vorhalb.area() == 0);
  Box Testobjekt_4 = Box(glm::vec3{20.0f, 0.0f, 0.0f}, glm::vec3{0.0f, 30.0f, 40.0f});
  REQUIRE(Testobjekt_4.area() == 5600);
  Box Testobjekt_5 = Box(glm::vec3{-35.0f, 10.0f, 20.0f}, glm::vec3{22.0f, -5.0f, 0.0f});
  REQUIRE(Testobjekt_5.area() == 5160);
}

TEST_CASE("member function volume taste box", "[volume,box]"){
  Box Testobjekt_6 = Box();
  REQUIRE(Testobjekt_6.volume() == 0);
  Box Testobjekt_7 = Box(glm::vec3{0.0f, 30.0f, 40.0f}, glm::vec3{20.0f, 0.0f, 0.0f});
  REQUIRE(Testobjekt_7.volume() == 24000);
  Box Testobjekt_8 = Box(glm::vec3{-35.0f, 10.0f, 20.0f}, glm::vec3{22.0f, -5.0f, 0.0f});
  REQUIRE(Testobjekt_8.volume() == 17100);
}

TEST_CASE("taste sphere constructor II", "[constructor,sphere]"){
  Sphere Testobjekt_9 = Sphere(glm::vec3{}, 25.0f, "Elisabeth", Color{0.5f, 0.5f, 0.5f});
  REQUIRE(Testobjekt_9.area() == Approx(7853.98f));
}

TEST_CASE("taste box constructor II", "[constructor,box]"){
  Box Testobjekt_10 = Box(glm::vec3{-35.0f, 10.0f, 20.0f}, glm::vec3{22.0f, -5.0f, 0.0f}, "Peter", Color{0.5f, 0.5f, 0.5f});
  REQUIRE(Testobjekt_10.area() == 5160);
}


TEST_CASE("taste for print of sphere and box", "[print,sphere,box]"){
  Box Testobjekt_11 = Box(glm::vec3{-35.0f, 10.0f, 20.0f}, glm::vec3{22.0f, -5.0f, 0.0f}, "Peter", Color{0.5f, 0.5f, 0.5f});
  Sphere Testobjekt_12 = Sphere(glm::vec3{40.0f, 10.0f, 7.0f}, 25.0f, "Elisabeth", Color{0.5f, 0.5f, 0.5f});
  std::cout << "Aufgabe 5.5: \n" << Testobjekt_11 << Testobjekt_12 << std::endl;
}


int main(int argc, char *argv[]){
  std::cout << "Ich bin sehr dumm \n";
  return Catch::Session().run(argc, argv);
}
