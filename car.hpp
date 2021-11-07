#pragma once
#include <string>
class Car {
public:
  Car(std::string name);
  static Car FromFile(std::string path);
  void printInfo();
  void start();

private:
  const std::string name;
  std::string status;
};
