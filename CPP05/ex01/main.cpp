#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
  try {
    Bureaucrat sarah("Sarah", 25);
    Form permit("Building permit", 50, 20);

    std::cout << permit << std::endl;
    sarah.signForm(permit);
    std::cout << permit << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  return 0;
}
