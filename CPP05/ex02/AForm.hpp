#ifndef AFORM_HPP
#define AFORM_HPP

#include <exception>
#include <iostream>
#include <string>

class Bureaucrat;

class AForm {
public:
  AForm();
  AForm(const std::string &name, int gradeToSign, int gradeToExecute);
  AForm(const AForm &other);
  virtual ~AForm();
  AForm &operator=(const AForm &other);

  const std::string &getName() const;
  bool getIsSigned() const;
  int getGradeToSign() const;
  int getGradeToExecute() const;

  void beSigned(const Bureaucrat &bureaucrat);
  virtual void execute(const Bureaucrat &executor) const = 0;

  class GradeTooHighException : public std::exception {
  public:
    const char *what() const throw();
  };

  class GradeTooLowException : public std::exception {
  public:
    const char *what() const throw();
  };

  class NotSignedException : public std::exception {
  public:
    const char *what() const throw();
  };

protected:
  void checkExecutable(const Bureaucrat &executor) const;

private:
  const std::string name;
  bool isSigned;
  const int gradeToSign;
  const int gradeToExecute;
};

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif
