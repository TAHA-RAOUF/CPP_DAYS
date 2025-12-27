/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moraouf <moraouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 22:38:49 by moraouf           #+#    #+#             */
/*   Updated: 2025/12/27 23:02:20 by moraouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP






#include <iostream>
#include <cmath>



class Fixed
{
    private:
        int                fixedPointValue;
        static const int    fractionalBits = 8;
    public:
        Fixed();
        Fixed(float const number);
        Fixed(int const number);
        ~Fixed();
        Fixed(const Fixed &object);
        Fixed& operator=(const Fixed &object);
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float  toFloat( void ) const;
        int    toInt( void ) const;
        
        bool operator>(const Fixed &object) const;
        bool operator<(const Fixed &object) const; 
        bool operator>=(const Fixed &object) const;
        bool operator<=(const Fixed &object) const;
        bool operator==(const Fixed &object) const;
        bool operator!=(const Fixed &object) const;

        Fixed operator+(const Fixed &object) const;
        Fixed operator-(const Fixed &object) const;
        Fixed operator*(const Fixed &object) const;
        Fixed operator/(const Fixed &object) const;
        Fixed operator++();
        Fixed operator++(int);
        Fixed operator--();
        Fixed operator--(int);

        static Fixed& min(Fixed &a, Fixed &b);
        static Fixed& max(Fixed &a, Fixed &b);
        static const Fixed& min(const Fixed &a, const Fixed &b);
        static const Fixed& max(const Fixed &a, const Fixed &b);
        
};

std::ostream& operator<<(std::ostream &out, const Fixed &fixed);





#endif