/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moraouf <moraouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 00:53:31 by moraouf           #+#    #+#             */
/*   Updated: 2025/12/27 00:59:14 by moraouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


Fixed::Fixed( void ) : fixedPointValue(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &object)
{
    std::cout << "Copy constructor called" << std::endl;
    this->fixedPointValue = object.getRawBits();
}
Fixed& Fixed::operator=(const Fixed &object)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &object)
    {
        this->fixedPointValue = object.getRawBits();
    }
    return (*this);
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->fixedPointValue);
}

void Fixed::setRawBits( int const raw )
{
    std::cout << "setRawBits member function called" << std::endl;
    this->fixedPointValue = raw;
}
Fixed::~Fixed( void )
{
    std::cout << "Destructor called" << std::endl;
}