/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taharaouf <taharaouf@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 18:57:47 by moraouf           #+#    #+#             */
/*   Updated: 2025/12/23 21:35:53 by taharaouf        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"


int main()
{
    std::cout << "----- HumanA Test/ Reference based -----" << std::endl;
    Weapon club = Weapon("crude spiked club");
    HumanA wolf("Black", club);
    wolf.attack();
    club.setType("some other type of club");
    wolf.attack();
    std::cout << "---------------------" << std::endl;
    std::cout << "----- HumanB Test/ Pointer based -----" <<  std::endl;
    HumanB zombie("Wolf");
    zombie.setWeapon(club);
    zombie.attack();
    club.setType("a new type of club");
    zombie.attack();
    return 0;
}