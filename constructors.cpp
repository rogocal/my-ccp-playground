#include "car.hpp"
#include <filesystem>
#include <iostream>
#include <unistd.h>
#include <vector>

int main() {
  char tmp[256];
  getcwd(tmp, 256);
  std::vector<Car *> list;
  std::cout << "Hola from " << tmp << '\n';
  auto car1 = Car::FromFile("../data/myCar.json");
  auto car2 = Car("Renault");
  auto car3 = Car::FromFile("../data/otherCar.json");
  list.push_back(&car1);
  list.push_back(&car2);
  list.push_back(&car3);
  car3.start();
  for (auto c : list) {
      c->printInfo();
  }
}
