/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moraouf <moraouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 18:57:47 by moraouf           #+#    #+#             */
/*   Updated: 2025/12/24 18:32:19 by moraouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

// int main()
// {
//     std::cout << "----- HumanA Test/ Reference based -----" << std::endl;
//     Weapon club = Weapon("crude spiked club");
//     HumanA wolf("Black", club);
//     wolf.attack();
//     club.setType("some other type of club");
//     wolf.attack();
//     std::cout << "---------------------" << std::endl;
//     std::cout << "----- HumanB Test/ Pointer based -----" <<  std::endl;
//     HumanB zombie("Wolf");
//     zombie.setWeapon(club);
//     zombie.attack();
//     club.setType("a new type of club");
//     zombie.attack();
//     return 0;
// }

int main()
{
    {
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
    {
        Weapon club = Weapon("crude spiked club");
        HumanB jim("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }
    return 0;
}