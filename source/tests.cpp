#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtx/intersect.hpp>
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

TEST_CASE("intersect_ray_sphere", "[intersect]"){
  // RAY
  glm::vec3 ray_origin{0.0f, 0.0f, 0.0f};
  // ray direction has to be normalized !
  // you can use :
  //  v = glm::normalize(some_vector)
  glm::vec3 ray_direction{1.0f, 0.0f, 0.0f};

  // Sphere
  glm::vec3 sphere_center{30.0f, 0.0f, 0.0f};
  float sphere_radius{5.0f};

  float distance = 0.0f;
  auto result = glm::intersectRaySphere(ray_origin, glm::normalize(ray_direction), sphere_center, sphere_radius * sphere_radius, distance);
  REQUIRE(result);
  REQUIRE(distance == 25.0f);
  glm::vec3 ray_origin_2{0.0f, 0.0f, 0.0f};
  glm::vec3 ray_direction_2{0.0f, -1.0f, 0.0f};
  glm::vec3 sphere_center_2{0.0f , 30.0f, 0.0f};
  float sphere_radius_2{7.5f};
  float distance_2 = 0.0f;
  bool result_2 = glm::intersectRaySphere(ray_origin_2, glm::normalize(ray_direction_2), sphere_center_2, sphere_radius_2 * sphere_radius_2, distance_2);
  REQUIRE(result_2 == false);
  Sphere Testobjekt_13 = Sphere(glm::vec3{30.0f, 0.0f, 0.0f}, 5.0f, "Odin", Color{0.5f, 0.5f, 0.5f});
  Ray Testobjekt_13_ray = Ray{glm::vec3{0.0f, 0.0f, 0.0f}, glm::vec3{1.0f, 0.0f, 0.0f}};
  HitPoint Testobjekt_13_hit = Testobjekt_13.intersect(Testobjekt_13_ray);
  REQUIRE(Testobjekt_13_hit.hit);
  //REQUIRE(Testobjekt_13_hit.distance_to_hit == 25.0f);
  glm::vec3 hit_direction = Testobjekt_13_hit.direction_of_hit;
  REQUIRE(hit_direction.x == 1.0f); REQUIRE(hit_direction.y == 0.0f); REQUIRE(hit_direction.z == 0.0f);
  glm::vec3 hit_point = Testobjekt_13_hit.point_of_hit;
  REQUIRE(hit_point.x == Testobjekt_13_hit.distance_to_hit); REQUIRE(hit_point.y == 0.0f); REQUIRE(hit_point.z == 0.0f);
  REQUIRE(Testobjekt_13_hit.name_of_hit == "Odin");
  Color hit_color = Testobjekt_13_hit.color_of_hit;
  REQUIRE(hit_color.r == 0.5f); REQUIRE(hit_color.g == 0.5f); REQUIRE(hit_color.b == 0.5f);
  Sphere Testobjekt_14 = Sphere(glm::vec3{10.0f, 10.0f, 10.0f}, 3.0f, "Kratus", Color{0.5f, 0.5f, 0.5f});
  Ray Testobjekt_14_ray = Ray{glm::vec3{0.0f, 0.0f, 0.0f}, glm::vec3{-1.0f, -1.0f, 0.0f}};
  HitPoint Testobjekt_14_hit = Testobjekt_14.intersect(Testobjekt_14_ray);
  REQUIRE(Testobjekt_14_hit.hit == false);
}

TEST_CASE("Aufgabe 5.8, virtual", "[5.8]"){
  std::cout << "aufgabe 5.8: \n";
  Color red{255, 0, 0};
  glm::vec3 position{0.0f, 0.0f, 0.0f};

  Sphere* s1 = new Sphere{position, 1.2f, "sphere0", red};
  Shape* s2 = new Sphere{position, 1.2f, "sphere1", red};

  s1->print(std::cout);
  s2->print(std::cout);

  delete s1;
  delete s2;

  REQUIRE(true);
}

int main(int argc, char *argv[]){
  std::cout << "Ich bin sehr dumm \n";
  return Catch::Session().run(argc, argv);
}
