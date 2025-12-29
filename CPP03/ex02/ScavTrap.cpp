/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moraouf <moraouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 14:58:45 by moraouf           #+#    #+#             */
/*   Updated: 2025/12/29 16:24:19 by moraouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"





ScavTrap::ScavTrap() : ClapTrap("Default_ScavTrap")
{
    this->hitpoints = 100;
    this->energypoints = 50;
    this->attackdamage = 20;
    std::cout << "ScavTrap " << this->name << " created." <<  std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
    this->hitpoints = 100;
    this->energypoints = 50;
    this->attackdamage = 20;
    std::cout << "ScavTrap " << this->name << " created." <<  std::endl;
}
ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
    std::cout << "ScavTrap " << this->name << " copied." << std::endl;
    *this = other;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
    }
    return *this;
}

void ScavTrap::attack(const std::string& target)
{
    if (this->energypoints > 0 && this->hitpoints > 0)
    {
        this->energypoints--;
        std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attackdamage << " points of damage!" << std::endl;
    }
    else
    {
        std::cout << "ScavTrap " << this->name << " cannot attack due to insufficient energy or hit points." << std::endl;
    }
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode." << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << this->name << " destroyed." << std::endl;
}