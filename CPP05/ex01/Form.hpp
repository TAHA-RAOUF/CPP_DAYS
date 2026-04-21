#ifndef FORM_HPP
#define FORM_HPP

#include <exception>
#include <iostream>
#include <string>

class Bureaucrat;

class Form {
public:
  Form();
  Form(const std::string &name, int gradeToSign, int gradeToExecute);
  Form(const Form &other);
  ~Form();
  Form &operator=(const Form &other);

  std::string getName() const;
  bool getIsSigned() const;
  int getGradeToSign() const;
  int getGradeToExecute() const;

  void beSigned(const Bureaucrat &bureaucrat);

  class GradeTooHighException : public std::exception {
  public:
    const char *what() const throw();
  };

  class GradeTooLowException : public std::exception {
  public:
    const char *what() const throw();
  };

private:
  const std::string name;
  bool isSigned;
  const int gradeToSign;
  const int gradeToExecute;
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif