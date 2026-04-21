#include "AForm.hpp"

#include "Bureaucrat.hpp"



AForm::AForm() : name("Default"), isSigned(false), gradeToSign(150), gradeToExecute(150) {
    std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute)
    : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
        std::cout << "AForm parameterized constructor called" << std::endl;
    }

AForm::AForm(const AForm &other)
    : name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign),
      gradeToExecute(other.gradeToExecute) {
        std::cout << "AForm copy constructor called" << std::endl;
    }

AForm::~AForm() {
    std::cout << "AForm destructor called" << std::endl;
}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > this->gradeToSign)
        throw GradeToolowException();
    this->isSigned = true;
}
bool AForm::getIsSigned() const {
    return this->isSigned;
}
const std::string &AForm::getName() const {
    return this->name;
}
int AForm::getGradeToSign() const {
    return this->gradeToSign;
}
int AForm::getGradeToExecute() const {
    return this->gradeToExecute;
}

AForm &AForm::operator=(const AForm &other) {
    std::cout << "AForm copy assignment operator called" << std::endl;
    if (this != &other)
        this->isSigned = other.isSigned;
    return *this;
}

AForm::AForm::execute(const Bureaucrat &executor) const {
    if (!this->isSigned)
        throw NotSignedException();
    if (executor.getGrade() > this->gradeToExecute)
        throw GradeToolowException();
    executeAction();
}