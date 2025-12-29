/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moraouf <moraouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 16:31:43 by moraouf           #+#    #+#             */
/*   Updated: 2025/12/29 16:32:12 by moraouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"



int main()
{
    FragTrap ft1("Taha");
    FragTrap ft2("Mehdi");

    ft1.attack("Mehdi");
    ft2.takeDamage(40);
    ft2.beRepaired(25);
    ft2.attack("Taha");
    ft1.takeDamage(50);
    ft1.highFivesGuys();
    return 0;
}




