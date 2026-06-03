#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

Bureaucrat::Bureaucrat() : name("Default"), grade(150) {
  std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name) {
  std::cout << "Bureaucrat parameterized constructor called" << std::endl;
  if (grade < 1)
    throw GradeTooHighException();
  if (grade > 150)
    throw GradeTooLowException();
  this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
    : name(other.name), grade(other.grade) {
  std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat() {
  std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
  std::cout << "Bureaucrat copy assignment operator called" << std::endl;
  if (this != &other)
    this->grade = other.grade;
  return *this;
}

std::string Bureaucrat::getName() const { return this->name; }

int Bureaucrat::getGrade() const { return this->grade; }

void Bureaucrat::incrementGrade() {
  if (this->grade - 1 < 1)
    throw GradeTooHighException();
  this->grade--;
}

void Bureaucrat::decrementGrade() {
  if (this->grade + 1 > 150)
    throw GradeTooLowException();
  this->grade++;
}

void Bureaucrat::signForm(AForm &form) const {
  try {
    form.beSigned(*this);
    std::cout << this->name << " signed " << form.getName() << std::endl;
  } catch (std::exception &e) {
    std::cout << this->name << " couldn't sign " << form.getName()
              << " because " << e.what() << std::endl;
  }
}

void Bureaucrat::executeForm(const AForm &form) const {
  try {
    form.execute(*this);
    std::cout << this->name << " executed " << form.getName() << std::endl;
  } catch (std::exception &e) {
    std::cout << this->name << " couldn't execute " << form.getName()
              << " because " << e.what() << std::endl;
  }
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
  return "Grade is too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
  return "Grade is too low!";
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b) {
  os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
  return os;
}
