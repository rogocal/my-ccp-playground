#include "car.hpp"
#include <fstream>
#include <iostream>
#include <json/json.h>
#include <json/reader.h>
#include <sstream>

Car::Car(std::string name) : name(name) { status = "stopped"; }
Car Car::FromFile(std::string path) {
  Json::Value root;
  std::ifstream config_doc(path, std::ifstream::binary);
  config_doc >> root;
  std::string name = root.get("carName", "FAIL").asString();
  return Car(name);
}
void Car::printInfo() {
  std::cout << "Car " << name << " status: " << status << '\n';
}
void Car::start() { status = "running"; }