/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moraouf <moraouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 15:37:51 by moraouf           #+#    #+#             */
/*   Updated: 2026/04/11 15:20:00 by moraouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main() {
  std::cout << "=== Test 1: Valid Bureaucrat ===" << std::endl;
  try {
    Bureaucrat bob("Bob", 42);
    std::cout << bob << std::endl;
  } catch (std::exception &e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }

  std::cout << std::endl;
  std::cout << "=== Test 2: Grade too high (0) ===" << std::endl;
  try {
    Bureaucrat highGuy("HighGuy", 0);
    std::cout << highGuy << std::endl;
  } catch (std::exception &e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }

  std::cout << std::endl;
  std::cout << "=== Test 3: Grade too low (151) ===" << std::endl;
  try {
    Bureaucrat lowGuy("LowGuy", 151);
    std::cout << lowGuy << std::endl;
  } catch (std::exception &e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }

  std::cout << std::endl;
  std::cout << "=== Test 4: Increment to grade too high ===" << std::endl;
  try {
    Bureaucrat top("Top", 1);
    std::cout << top << std::endl;
    top.incrementGrade();
  } catch (std::exception &e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }

  std::cout << std::endl;
  std::cout << "=== Test 5: Decrement to grade too low ===" << std::endl;
  try {
    Bureaucrat bottom("Bottom", 150);
    std::cout << bottom << std::endl;
    bottom.decrementGrade();
  } catch (std::exception &e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }

  std::cout << std::endl;
  std::cout << "=== Test 6: Normal increment/decrement ===" << std::endl;
  try {
    Bureaucrat mid("Mid", 75);
    std::cout << mid << std::endl;
    mid.incrementGrade();
    std::cout << "After increment: " << mid << std::endl;
    mid.decrementGrade();
    std::cout << "After decrement: " << mid << std::endl;
  } catch (std::exception &e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }

  return 0;
}
