/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moraouf <moraouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 15:19:32 by moraouf           #+#    #+#             */
/*   Updated: 2025/12/29 16:24:21 by moraouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
    


int main()
{
    ScavTrap st1("Taha");
    ScavTrap st2("mehdi");

    st1.attack("mehdi");
    st2.takeDamage(30);
    st2.beRepaired(20);
    st2.attack("Taha");
    st1.takeDamage(40);
    st1.guardGate();
    return 0;
}


