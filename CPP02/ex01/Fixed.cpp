/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moraouf <moraouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 21:22:47 by moraouf           #+#    #+#             */
/*   Updated: 2025/12/27 21:53:02 by moraouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


Fixed::Fixed( void ) : fixedPointValue(0)
{
    std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(float const number)
{
    std::cout << "Float constructor called" << std::endl;
    this->fixedPointValue = roundf(number * (1 << fractionalBits));    
}
Fixed::Fixed(int const number)
{
    std::cout << "Int constructor called" << std::endl;
    this->fixedPointValue = number << fractionalBits;
}
Fixed::~Fixed( void )
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &object)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = object;
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
    // std::cout << "getRawBits member function called" << std::endl;
    return (this->fixedPointValue);
}

void Fixed::setRawBits( int const raw )
{
    // std::cout << "setRawBits member function called" << std::endl;
    this->fixedPointValue = raw;
}

float Fixed::toFloat( void ) const
{
    return ((float)this->fixedPointValue / (1 << fractionalBits));
}
    
int Fixed::toInt( void ) const
{
    return (this->fixedPointValue >> fractionalBits);
}

std::ostream& operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return (out);
}



