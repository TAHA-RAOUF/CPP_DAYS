/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moraouf <moraouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 19:31:42 by moraouf           #+#    #+#             */
/*   Updated: 2025/12/28 19:42:30 by moraouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP



#include <iostream>



class ClapTrap 
{
    public:
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap &other);
        ClapTrap &operator=(const ClapTrap &other);
        ~ClapTrap();
        void attack(const std::string &target);
        void takeDamage(unsigned int amount);   
        void beRepaired(unsigned int amount);
    private:
        std::string name;
        int hitpoints;
        int energypoints;
        int attackdamage;    
};  



#endif