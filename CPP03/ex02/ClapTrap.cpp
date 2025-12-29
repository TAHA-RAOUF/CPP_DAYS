/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moraouf <moraouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 13:49:30 by moraouf           #+#    #+#             */
/*   Updated: 2025/12/29 16:24:18 by moraouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): name("Default"), hitpoints(10), energypoints(10), attackdamage(0)
{
     std::cout << "ClapTrap Default constructor called" << std::endl;
}
ClapTrap::ClapTrap(const std::string& name): name(name), hitpoints(10), energypoints(10), attackdamage(0)
{
     std::cout << "ClapTrap Parameterized constructor called" << std::endl;
}
ClapTrap::ClapTrap(const ClapTrap &other)
{
    std::cout << "ClapTrap Copy constructor called" << std::endl;
    *this = other;
}
ClapTrap& ClapTrap::operator=(const ClapTrap &other)
{
    if (this != &other)
    {
        name = other.name;
        hitpoints = other.hitpoints;
        energypoints = other.energypoints;
        attackdamage = other.attackdamage;
    }
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
    if (energypoints > 0 && hitpoints > 0)
    {
        energypoints--;
        std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackdamage << " points of damage!" << std::endl;
    }
    else    
    {
        std::cout << "ClapTrap " << name << " has no energy or hit points left to attack!" << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    hitpoints -= amount;
    if (hitpoints < 0)
        hitpoints = 0;
    std::cout << "ClapTrap " << name << " takes " << amount << " points of damage! Remaining hit points: " << hitpoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (energypoints > 0 && hitpoints > 0)
    {
        energypoints--;
        hitpoints += amount;
        std::cout << "ClapTrap " << name << " is repaired by " << amount << " points! Current hit points: " << hitpoints << std::endl;
    }
    else
    {
        std::cout << "ClapTrap " << name << " has no energy or hit points left to repair!" << std::endl;
    }
}

