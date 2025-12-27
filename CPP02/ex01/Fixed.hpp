/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moraouf <moraouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 21:19:06 by moraouf           #+#    #+#             */
/*   Updated: 2025/12/27 21:47:10 by moraouf          ###   ########.fr       */
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
};

std::ostream& operator<<(std::ostream &out, const Fixed &fixed);



#endif