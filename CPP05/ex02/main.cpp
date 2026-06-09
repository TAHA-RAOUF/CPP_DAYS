#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

static void testForm(Bureaucrat &bureaucrat, AForm &form)
{
  bureaucrat.signForm(form);
  bureaucrat.executeForm(form);
  std::cout << std::endl;
}

int main()
{
  try {
    Bureaucrat boss("Olivia", 1);
    ShrubberyCreationForm shrubbery("home");
    RobotomyRequestForm robotomy("Bender");
    PresidentialPardonForm pardon("Daniel");

    testForm(boss, shrubbery);
    testForm(boss, robotomy);
    testForm(boss, pardon);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  return 0;
}
