/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moraouf <moraouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 23:59:38 by moraouf           #+#    #+#             */
/*   Updated: 2025/12/27 00:56:23 by moraouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP




#include <iostream>



class Fixed
{
    private:
        int                fixedPointValue;
        static const int    fractionalBits = 8;
    public:
        Fixed();
        ~Fixed();
        Fixed(const Fixed &object);
        Fixed& operator=(const Fixed &object);
        int getRawBits( void ) const;
        void setRawBits( int const raw );
};




#endif