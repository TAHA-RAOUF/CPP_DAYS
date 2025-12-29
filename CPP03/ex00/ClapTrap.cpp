/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moraouf <moraouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 19:34:39 by moraouf           #+#    #+#             */
/*   Updated: 2025/12/29 14:49:32 by moraouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Default"), hitpoints(10), energypoints(10), attackdamage(0)
{
    std::cout << "ClapTrap " << this->name << " created." << std::endl;
}
ClapTrap::ClapTrap(std::string name) : name(name), hitpoints(10), energypoints(10), attackdamage(0)
{
    std::cout << "ClapTrap " << this->name << " created." << std::endl;
}
ClapTrap::ClapTrap(const ClapTrap &other)
{
    std::cout << "ClapTrap " << other.name << " copied." << std::endl;
    *this = other;
}
ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    if (this != &other)
    {
        this->name = other.name;
        this->hitpoints = other.hitpoints;
        this->energypoints = other.energypoints;
        this->attackdamage = other.attackdamage;
    }
    return *this;
}
ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << this->name << " destroyed." << std::endl;   
}
void ClapTrap::attack(const std::string &target)
{
    if (this->energypoints > 0 && this->hitpoints > 0)
    {
        this->energypoints--;
        std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackdamage << " points of damage!" << std::endl;
    }
    else
    {
        std::cout << "ClapTrap " << this->name << " has no energy or hit points left to attack!" << std::endl;
    }
}
void ClapTrap::takeDamage(unsigned int amount)
{
    this->hitpoints -= amount;
    if (this->hitpoints < 0)
        this->hitpoints = 0;
    std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage! Remaining hit points: " << this->hitpoints << std::endl;
}
void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->energypoints > 0 && this->hitpoints > 0)
    {
        this->energypoints--;
        this->hitpoints += amount;
        std::cout << "ClapTrap " << this->name << " is repaired by " << amount << " points! Current hit points: " << this->hitpoints << std::endl;
    }
    else
    {
        std::cout << "ClapTrap " << this->name << " has no energy or hit points left to repair!" << std::endl;
    }
}