/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moraouf <moraouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 19:13:55 by moraouf           #+#    #+#             */
/*   Updated: 2025/12/28 19:42:16 by moraouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"


int main()
{
    ClapTrap ct1("Clappy");
    ClapTrap ct2("Trapster");

    ct1.attack("Trapster");
    ct2.takeDamage(5);
    ct2.beRepaired(3);
    ct2.attack("Clappy");
    ct1.takeDamage(7);
    return 0;
}