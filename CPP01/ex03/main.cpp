/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moraouf <moraouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 18:57:47 by moraouf           #+#    #+#             */
/*   Updated: 2025/12/23 19:00:17 by moraouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"


int main()
{
    Weapon club = Weapon("crude spiked club");
    HumanA wolf("Black", club);
    wolf.attack();
    club.setType("some other type of club");
    wolf.attack();
    std::cout << "---------------------" << std::endl;
    HumanB zombie("Wolf");
    zombie.setWeapon(club);
    zombie.attack();
    club.setType("a new type of club");
    zombie.attack();
    return 0;
}