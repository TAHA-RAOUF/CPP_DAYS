#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <iostream>

static void signAndExecute(Bureaucrat &bureaucrat, AForm *form) {
  if (!form)
    return;

  std::cout << *form << std::endl;
  bureaucrat.signForm(*form);
  bureaucrat.executeForm(*form);
  delete form;
}

int main() {
  std::cout << "=== Test 1: Intern creates shrubbery ===" << std::endl;
  try {
    Intern intern;
    Bureaucrat boss("Boss", 1);
    AForm *form = intern.makeForm("shrubbery creation", "home");

    signAndExecute(boss, form);
  } catch (std::exception &e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }

  std::cout << std::endl;
  std::cout << "=== Test 2: Intern creates robotomy ===" << std::endl;
  try {
    Intern intern;
    Bureaucrat boss("Boss", 1);
    AForm *form = intern.makeForm("robotomy request", "Marvin");

    signAndExecute(boss, form);
  } catch (std::exception &e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }

  std::cout << std::endl;
  std::cout << "=== Test 3: Intern creates pardon ===" << std::endl;
  try {
    Intern intern;
    Bureaucrat boss("Boss", 1);
    AForm *form = intern.makeForm("presidential pardon", "Ford");

    signAndExecute(boss, form);
  } catch (std::exception &e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }

  std::cout << std::endl;
  std::cout << "=== Test 4: Unknown form name ===" << std::endl;
  try {
    Intern intern;
    Bureaucrat boss("Boss", 1);
    AForm *form = intern.makeForm("coffee request", "Desk");

    signAndExecute(boss, form);
  } catch (std::exception &e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }

  return 0;
}
