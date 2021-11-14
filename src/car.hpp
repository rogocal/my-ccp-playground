#pragma once
#include <exception>
#include <string>

class CarException : public std::exception {
public:
  CarException(const std::string &msg) : m_msg(msg) {}
  ~CarException() = default;
  virtual const char *what() const throw() { return m_msg.c_str(); }
  const std::string m_msg;
};

class Car {
public:
  Car();
  Car(std::string name);
  static Car FromFile(std::string path);
  void printInfo();
  void start();

private:
  const std::string name;
  std::string status;
};
