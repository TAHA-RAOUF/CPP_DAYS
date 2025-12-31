/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moraouf <moraouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 17:26:20 by moraouf           #+#    #+#             */
/*   Updated: 2025/12/31 15:12:28 by moraouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"


Animal::Animal() : type("Animal")
{
    std::cout << "Animal Default constructor called" << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal Destructor called" << std::endl;
}
Animal::Animal(const Animal& other)
{
    std::cout << "Animal Copy constructor called" << std::endl;
    *this = other;
}
Animal& Animal::operator=(const Animal& other)
{
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}
void Animal::makeSound() const
{
    std::cout << "Animal makes a sound" << std::endl;
}
std::string Animal::getType() const
{
    return this->type;
}
