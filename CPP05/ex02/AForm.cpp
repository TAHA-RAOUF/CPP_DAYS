#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm()
    : name("Default"), isSigned(false), gradeToSign(150),
      gradeToExecute(150) {
  std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute)
    : name(name), isSigned(false), gradeToSign(gradeToSign),
      gradeToExecute(gradeToExecute) {
  std::cout << "AForm parameterized constructor called" << std::endl;
  if (this->gradeToSign < 1 || this->gradeToExecute < 1)
    throw GradeTooHighException();
  if (this->gradeToSign > 150 || this->gradeToExecute > 150)
    throw GradeTooLowException();
}

AForm::AForm(const AForm &other)
    : name(other.name), isSigned(other.isSigned),
      gradeToSign(other.gradeToSign),
      gradeToExecute(other.gradeToExecute) {
  std::cout << "AForm copy constructor called" << std::endl;
}

AForm::~AForm() {
  std::cout << "AForm destructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &other) {
  std::cout << "AForm copy assignment operator called" << std::endl;
  if (this != &other)
    this->isSigned = other.isSigned;
  return *this;
}

const std::string &AForm::getName() const { return this->name; }

bool AForm::getIsSigned() const { return this->isSigned; }

int AForm::getGradeToSign() const { return this->gradeToSign; }

int AForm::getGradeToExecute() const { return this->gradeToExecute; }

void AForm::beSigned(const Bureaucrat &bureaucrat) {
  if (bureaucrat.getGrade() > this->gradeToSign)
    throw GradeTooLowException();
  this->isSigned = true;
}

void AForm::checkExecutable(const Bureaucrat &executor) const {
  if (!this->isSigned)
    throw NotSignedException();
  if (executor.getGrade() > this->gradeToExecute)
    throw GradeTooLowException();
}

const char *AForm::GradeTooHighException::what() const throw() {
  return "Form grade is too high!";
}

const char *AForm::GradeTooLowException::what() const throw() {
  return "Form grade is too low!";
}

const char *AForm::NotSignedException::what() const throw() {
  return "Form is not signed!";
}

std::ostream &operator<<(std::ostream &os, const AForm &form) {
  os << "Form '" << form.getName() << "', signed: "
     << (form.getIsSigned() ? "yes" : "no")
     << ", grade required to sign: " << form.getGradeToSign()
     << ", grade required to execute: " << form.getGradeToExecute() << ".";
  return os;
}
