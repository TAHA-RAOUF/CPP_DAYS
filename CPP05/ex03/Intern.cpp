#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

Intern::Intern() {
  std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern &other) {
  std::cout << "Intern copy constructor called" << std::endl;
  (void)other;
}

Intern::~Intern() {
  std::cout << "Intern destructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &other) {
  std::cout << "Intern copy assignment operator called" << std::endl;
  (void)other;
  return *this;
}

AForm *Intern::makeForm(const std::string &formName,
                        const std::string &target) const {
  const std::string names[] = {"shrubbery creation", "robotomy request",
                               "presidential pardon"};

  for (int i = 0; i < 3; i++) {
    if (formName == names[i]) {
      std::cout << "Intern creates " << formName << std::endl;
      if (i == 0)
        return new ShrubberyCreationForm(target);
      if (i == 1)
        return new RobotomyRequestForm(target);
      return new PresidentialPardonForm(target);
    }
  }

  std::cout << "Intern couldn't create " << formName << std::endl;
  return NULL;
}
