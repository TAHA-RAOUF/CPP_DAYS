#include "Bureaucrat.hpp"
#include <iostream>

int main() {
  try {
    Bureaucrat alice("Alice", 2);

    std::cout << alice << std::endl;
    alice.incrementGrade();
    std::cout << alice << std::endl;
    alice.decrementGrade();
    std::cout << alice << std::endl;

    Bureaucrat john("John", 151);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  return 0;
}

// try = test dangerous code
// throw = send an error
// catch = receive the error
// what() = message of the error
