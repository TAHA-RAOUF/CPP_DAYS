/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moraouf <moraouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 17:31:55 by moraouf           #+#    #+#             */
/*   Updated: 2025/12/30 18:15:47 by moraouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"



Cat::Cat() : Animal()
{
    this->type = "Cat";
    std::cout << "Cat constructor called" << std::endl;
}
Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
}
Cat::Cat(const Cat& other) : Animal(other)
{
    std::cout << "Cat copy constructor called" << std::endl;
    *this = other;
}
Cat& Cat::operator=(const Cat& other)
{
    if (this != &other)
    {
        Animal::operator=(other);
    }
    return *this;
}
void Cat::makeSound() const
{
    std::cout << "Meow Meow!" << std::endl;
}