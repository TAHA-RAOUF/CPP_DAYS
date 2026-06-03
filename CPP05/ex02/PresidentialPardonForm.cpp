#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("PresidentialPardonForm", 25, 5), target("Default") {
  std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("PresidentialPardonForm", 25, 5), target(target) {
  std::cout << "PresidentialPardonForm parameterized constructor called"
            << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm &other)
    : AForm(other), target(other.target) {
  std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
  std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

PresidentialPardonForm &
PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
  std::cout << "PresidentialPardonForm copy assignment operator called"
            << std::endl;
  if (this != &other) {
    AForm::operator=(other);
    this->target = other.target;
  }
  return *this;
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
  checkExecutable(executor);
  std::cout << this->target << " has been pardoned by Zaphod Beeblebrox"
            << std::endl;
}
