#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int main() {
  std::cout << "=== Test 1: Shrubbery success ===" << std::endl;
  try {
    Bureaucrat alice("Alice", 1);
    ShrubberyCreationForm shrubbery("garden");

    std::cout << shrubbery << std::endl;
    alice.signForm(shrubbery);
    alice.executeForm(shrubbery);
  } catch (std::exception &e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }

  std::cout << std::endl;
  std::cout << "=== Test 2: Robotomy success/failure random ===" << std::endl;
  try {
    Bureaucrat bob("Bob", 1);
    RobotomyRequestForm robotomy("Bender");

    bob.signForm(robotomy);
    bob.executeForm(robotomy);
  } catch (std::exception &e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }

  std::cout << std::endl;
  std::cout << "=== Test 3: Presidential pardon ===" << std::endl;
  try {
    Bureaucrat president("President", 1);
    PresidentialPardonForm pardon("Arthur");

    president.signForm(pardon);
    president.executeForm(pardon);
  } catch (std::exception &e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }

  std::cout << std::endl;
  std::cout << "=== Test 4: Execute unsigned form ===" << std::endl;
  try {
    Bureaucrat chief("Chief", 1);
    ShrubberyCreationForm unsignedForm("unsigned");

    chief.executeForm(unsignedForm);
  } catch (std::exception &e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }

  std::cout << std::endl;
  std::cout << "=== Test 5: Grade too low to execute ===" << std::endl;
  try {
    Bureaucrat signer("Signer", 1);
    Bureaucrat low("Low", 150);
    ShrubberyCreationForm form("low_grade");

    signer.signForm(form);
    low.executeForm(form);
  } catch (std::exception &e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }

  return 0;
}
