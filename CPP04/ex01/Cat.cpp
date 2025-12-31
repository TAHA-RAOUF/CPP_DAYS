/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moraouf <moraouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 17:31:55 by moraouf           #+#    #+#             */
/*   Updated: 2025/12/31 13:20:14 by moraouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"



Cat::Cat() : Animal()
{
    this->type = "Cat";
    this->brain = new Brain();
    std::cout << "Cat default constructor called" <<  std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{
    this->brain = new Brain(*(other.brain));
    this->type = other.type;
    // std::cout << "Cat copy constructor called" << std::endl;
}
Cat& Cat::operator=(const Cat& other)
{
    if(this != &other)
    {
        Animal::operator=(other);
        delete this->brain;
        this->brain = new Brain(*(other.brain));
    }
    // std::cout << "Cat assignment operator called" << std::endl;
    return *this;
}
std::string Cat::getType() const
{
    return this->type;
}

Brain* Cat::getBrain() const
{
    return this->brain;
}

Cat::~Cat()
{
    delete this->brain;
    std::cout << "Cat destructor called" <<  std::endl;
}


void Cat::makeSound() const
{
    std::cout << "Meow Meow!" << std::endl;
}