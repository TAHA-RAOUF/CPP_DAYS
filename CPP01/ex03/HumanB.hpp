/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taharaouf <taharaouf@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 18:27:59 by moraouf           #+#    #+#             */
/*   Updated: 2025/12/23 21:33:20 by taharaouf        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP


#include "Weapon.hpp"
#include <iostream>


class HumanB
{
    private:
        std::string name;
        Weapon*     weapon;
    public:
        void attack();
        void setWeapon(Weapon& weapGun);
        HumanB( std::string name );
        
};

#endif