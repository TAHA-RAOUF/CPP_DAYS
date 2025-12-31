/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moraouf <moraouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 17:49:47 by moraouf           #+#    #+#             */
/*   Updated: 2025/12/30 18:15:31 by moraouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
    std::cout << "WrongAnimal Default constructor called" << std::endl;
}
WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal Destructor called" << std::endl;
}
WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
    std::cout << "WrongAnimal Copy constructor called" << std::endl;
    *this = other;
}
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
    if(this != &other) {
        this->type = other.type;
    }   
    return *this;
}
void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal makes a sound" << std::endl;
}
std::string WrongAnimal::getType() const
{
    return this->type;
}
