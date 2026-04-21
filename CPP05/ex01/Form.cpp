#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("Default"), isSigned(false), gradeToSign(150), gradeToExecute(150) {
  std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
    : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
  std::cout << "Form parameterized constructor called" << std::endl;
  if (this->gradeToSign < 1 || this->gradeToExecute < 1)
    throw GradeTooHighException();
  if (this->gradeToSign > 150 || this->gradeToExecute > 150)
    throw GradeTooLowException();
}

Form::Form(const Form &other)
    : name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign),
      gradeToExecute(other.gradeToExecute) {
  std::cout << "Form copy constructor called" << std::endl;
}

Form::~Form() { std::cout << "Form destructor called" << std::endl; }

Form &Form::operator=(const Form &other) {
  std::cout << "Form copy assignment operator called" << std::endl;
  if (this != &other)
    this->isSigned = other.isSigned;
  return *this;
}

std::string Form::getName() const { return this->name; }

bool Form::getIsSigned() const { return this->isSigned; }

int Form::getGradeToSign() const { return this->gradeToSign; }

int Form::getGradeToExecute() const { return this->gradeToExecute; }

void Form::beSigned(const Bureaucrat &bureaucrat) {
  if (bureaucrat.getGrade() > this->gradeToSign)
    throw GradeTooLowException();
  this->isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw() {
  return "Form grade is too high!";
}

const char *Form::GradeTooLowException::what() const throw() {
  return "Form grade is too low!";
}

std::ostream &operator<<(std::ostream &os, const Form &form) {
  os << "Form '" << form.getName() << "', signed: "
     << (form.getIsSigned() ? "yes" : "no")
     << ", grade required to sign: " << form.getGradeToSign()
     << ", grade required to execute: " << form.getGradeToExecute() << ".";
  return os;
}
