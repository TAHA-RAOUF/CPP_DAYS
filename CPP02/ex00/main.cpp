/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moraouf <moraouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 00:12:00 by moraouf           #+#    #+#             */
/*   Updated: 2025/12/27 00:58:23 by moraouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"



int main()
{
    Fixed a;
    Fixed b(a);
    Fixed c;

    c = b;

    std::cout << "a.getRawBits(): " << a.getRawBits() << std::endl;
    std::cout << "b.getRawBits(): " << b.getRawBits() << std::endl;
}
