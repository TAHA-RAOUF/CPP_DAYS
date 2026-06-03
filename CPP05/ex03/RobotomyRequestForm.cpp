#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", 72, 45), target("Default") {
  std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("RobotomyRequestForm", 72, 45), target(target) {
  std::cout << "RobotomyRequestForm parameterized constructor called"
            << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm(other), target(other.target) {
  std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
  std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm &
RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
  std::cout << "RobotomyRequestForm copy assignment operator called"
            << std::endl;
  if (this != &other) {
    AForm::operator=(other);
    this->target = other.target;
  }
  return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
  checkExecutable(executor);

  std::cout << "* drilling noises *" << std::endl;
  std::srand(std::time(NULL));
  if (std::rand() % 2)
    std::cout << this->target << " has been robotomized successfully"
              << std::endl;
  else
    std::cout << this->target << " robotomy failed" << std::endl;
}
