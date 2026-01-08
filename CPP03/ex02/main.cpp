/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moraouf <moraouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 16:31:43 by moraouf           #+#    #+#             */
/*   Updated: 2025/12/30 13:53:31 by moraouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"



int main()
{

    ScavTrap scav("SC4V");
    FragTrap frag("FR4G");

    scav.attack("enemy");
    scav.guardGate();

    frag.attack("enemy");
    frag.highFivesGuys();

    return 0;
}




