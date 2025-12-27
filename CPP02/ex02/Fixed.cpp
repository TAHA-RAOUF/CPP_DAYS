/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moraouf <moraouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 22:59:06 by moraouf           #+#    #+#             */
/*   Updated: 2025/12/27 23:05:54 by moraouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed( void ) : fixedPointValue(0)
{
    // std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(float const number)
{
    // std::cout << "Float constructor called" << std::endl;
    this->fixedPointValue = roundf(number * (1 << fractionalBits));
}
Fixed::Fixed(int const number)
{
    // std::cout << "Int constructor called" << std::endl;
    this->fixedPointValue = number << fractionalBits;
}
Fixed::~Fixed( void )
{
    // std::cout << "Destructor called" << std::endl;
}
Fixed::Fixed(const Fixed &object)
{
    // std::cout << "Copy constructor called" << std::endl;
    *this = object;
}
Fixed& Fixed::operator=(const Fixed &object)
{
    // std::cout << "Copy assignment operator called" << std::endl;
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
    this->fixedPointValue = raw;
}
float Fixed::toFloat() const
{
    return(static_cast<float>(this->fixedPointValue) / (1 << fractionalBits));
}

int Fixed::toInt() const
{
    return(this->fixedPointValue >> fractionalBits);
}

std::ostream& operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return (out);
}

bool Fixed::operator>(const Fixed &object) const
{
    return (this->fixedPointValue > object.fixedPointValue);
}
bool Fixed::operator<(const Fixed &object) const
{
    return (this->fixedPointValue < object.fixedPointValue);
}
bool Fixed::operator>=(const Fixed &object) const
{
    return (this->fixedPointValue >= object.fixedPointValue);
}
bool Fixed::operator<=(const Fixed &object) const
{
    return (this->fixedPointValue <= object.fixedPointValue);
}
bool Fixed::operator==(const Fixed &object) const
{
    return (this->fixedPointValue == object.fixedPointValue);
}
bool Fixed::operator!=(const Fixed &object) const
{
    return (this->fixedPointValue != object.fixedPointValue);
}
Fixed Fixed::operator+(const Fixed &object) const
{
    return (Fixed(this->toFloat() + object.toFloat()));
}
Fixed Fixed::operator-(const Fixed &object) const
{
    return (Fixed(this->toFloat() - object.toFloat()));
}
Fixed Fixed::operator*(const Fixed &object) const
{
    return (Fixed(this->toFloat() * object.toFloat()));
}
Fixed Fixed::operator/(const Fixed &object) const
{
    return (Fixed(this->toFloat() / object.toFloat()));
}
Fixed Fixed::operator++()
{
    this->fixedPointValue++;
    return (*this);
}
Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    this->fixedPointValue++;
    return (temp);
}
Fixed Fixed::operator--()
{
    this->fixedPointValue--;
    return (*this);
}
Fixed Fixed::operator--(int)
{
    Fixed temp = *this;
    this->fixedPointValue--;
    return (temp);
}
Fixed& Fixed::min(Fixed &a, Fixed &b)
{
    return (a < b ? a : b);
}
Fixed& Fixed::max(Fixed &a, Fixed &b)
{
    return (a > b ? a : b);
}
const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
    return (a < b ? a : b);
}
const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
    return (a > b ? a : b);
}

