/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taharaouf <taharaouf@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 18:40:38 by moraouf           #+#    #+#             */
/*   Updated: 2025/12/23 21:33:04 by taharaouf        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef HUMANA_HPP
#define HUMANA_HPP



#include <iostream>
#include "Weapon.hpp"

class HumanA{
    private: 
        std::string name;
        Weapon&    weapon;

    public:
        void attack() const;
        HumanA(std::string name, Weapon& weapGun);
};



#endif