#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", 145, 137), target("Default") {
  std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", 145, 137), target(target) {
  std::cout << "ShrubberyCreationForm parameterized constructor called"
            << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(
    const ShrubberyCreationForm &other)
    : AForm(other), target(other.target) {
  std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
  std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
  std::cout << "ShrubberyCreationForm copy assignment operator called"
            << std::endl;
  if (this != &other) {
    AForm::operator=(other);
    this->target = other.target;
  }
  return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
  checkExecutable(executor);

  std::ofstream file((this->target + "_shrubbery").c_str());
  file << "       _-_\n"
       << "    /~~   ~~\\\n"
       << " /~~         ~~\\\n"
       << "{               }\n"
       << " \\  _-     -_  /\n"
       << "   ~  \\\\ //  ~\n"
       << "_- -   | | _- _\n"
       << "  _ -  | |   -_\n"
       << "      // \\\\\n";
}
