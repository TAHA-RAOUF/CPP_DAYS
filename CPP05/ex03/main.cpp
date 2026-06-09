#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <iostream>

int main() {
  try {
    Intern intern;
    AForm *form;
    Bureaucrat director("Maya", 1);

    form = intern.makeForm("robotomy request", "Alex");
    if (!form)
      return 1;
    director.signForm(*form);
    director.executeForm(*form);
    delete form;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  return 0;
}
