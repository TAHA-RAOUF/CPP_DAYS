/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moraouf <moraouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 17:30:29 by moraouf           #+#    #+#             */
/*   Updated: 2025/12/31 13:10:45 by moraouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
    this->type = "Dog";
    this->brain = new Brain();
    std::cout << "Dog default constructor called" <<  std::endl;
}
Dog::~Dog()
{
    delete this->brain;
    std::cout << "Dog destructor called" <<  std::endl;
}


Dog::Dog(const Dog& other) : Animal(other)
{
    brain = new Brain(*(other.brain));
    this->type = other.type;    
    // std::cout << "Dog copy constructor called" << std::endl;
}


Dog& Dog::operator=(const Dog& other)
{
    if(this != &other)
    {
        Animal::operator=(other);
        delete this->brain;
        this->brain = new Brain(*(other.brain));
    }
    // std::cout << "Dog assignment operator called" << std::endl;
    return *this;
}

std::string Dog::getType() const
{
    return this->type;
}


Brain* Dog::getBrain() const
{
    return this->brain;
}

void Dog::makeSound() const
{
    std::cout << "Woof Woof!" << std::endl;
}
