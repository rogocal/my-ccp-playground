#include "car.hpp"
#include <exception>
#include <iostream>
#include <vector>

int main() {
  std::vector<Car> list;
  bool initOK = false;
  try {
    list.push_back(Car::FromFile("../../data/myCar.json"));
    list.push_back(Car("Renault"));
    list.push_back(Car::FromFile("../../data/otherCar.json"));
    list.push_back(Car());
    initOK = true;
  } catch (CarException &e) {
    std::cerr << "CarException: " << e.what() << std::endl;
  } catch (std::exception &e) {
    std::cerr << "exception: " << e.what() << std::endl;
  }
  if (initOK) {
    list[1].start();
  }
  for (auto c : list) {
    c.printInfo();
  }
}
