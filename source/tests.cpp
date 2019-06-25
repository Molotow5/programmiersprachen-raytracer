#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <iostream>
#include "../framework/sphere.hpp"


TEST_CASE("taste for consturctor and area", "[area,constructor,sphere]"){
  Sphere Testobjekt_1 = Sphere();
  REQUIRE(Testobjekt_1.area() == 0);
  Sphere Testobjekt_2 = Sphere(glm::vec3{5.0f, 5.0f, 5.0f}, 25.0f);
  REQUIRE(Testobjekt_2.area() == Approx(7853.98f));
}

TEST_CASE("member funtion volume taste", "[volume,sphere]"){
  Sphere Testobjekt_3 = Sphere(glm::vec3{}, 5.0f);
  REQUIRE(Testobjekt_3.volume() == Approx(523.598));
}

int main(int argc, char *argv[])
{
  std::cout << "Ich bin sehr dumm \n"; 
  return Catch::Session().run(argc, argv);
}
