#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
  std::cout << "=== Test 1: Valid form and successful signature ===" << std::endl;
  try {
    Bureaucrat alice("Alice", 20);
    Form taxForm("Tax Form", 50, 30);

    std::cout << alice << std::endl;
    std::cout << taxForm << std::endl;

    alice.signForm(taxForm);
    std::cout << taxForm << std::endl;
  } catch (std::exception &e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }

  std::cout << std::endl;
  std::cout << "=== Test 2: Signature fails due to low bureaucrat grade ===" << std::endl;
  try {
    Bureaucrat bob("Bob", 120);
    Form secretForm("Secret Form", 60, 40);

    std::cout << bob << std::endl;
    std::cout << secretForm << std::endl;

    bob.signForm(secretForm);
    std::cout << secretForm << std::endl;
  } catch (std::exception &e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }

  std::cout << std::endl;
  std::cout << "=== Test 3: Form grade too high at construction ===" << std::endl;
  try {
    Form invalidHigh("Invalid High", 0, 10);    
    std::cout << invalidHigh << std::endl;
  } catch (std::exception &e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }

  std::cout << std::endl;
  std::cout << "=== Test 4: Form grade too low at construction ===" << std::endl;
  try {
    Form invalidLow("Invalid Low", 10, 151);
    std::cout << invalidLow << std::endl;
  } catch (std::exception &e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }

  std::cout << std::endl;
  std::cout << "=== Test 5: Direct beSigned() usage ===" << std::endl;
  try {
    Bureaucrat chief("Chief", 5);
    Form permit("Permit", 5, 10);

    std::cout << permit << std::endl;
    permit.beSigned(chief);
    std::cout << permit << std::endl;
  } catch (std::exception &e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }

  return 0;
}
