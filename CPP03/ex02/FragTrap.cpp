/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moraouf <moraouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 16:32:21 by moraouf           #+#    #+#             */
/*   Updated: 2025/12/29 16:38:16 by moraouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"


FragTrap::FragTrap() : ClapTrap("Default_FragTrap")
{
    this->hitpoints = 100;
    this->energypoints = 100;
    this->attackdamage = 30;
    std::cout << "FragTrap " << this->name << " created." <<  std::endl;
}
FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
    this->hitpoints = 100;
    this->energypoints = 100;
    this->attackdamage = 30;
    std::cout << "FragTrap " << this->name << " created." <<  std::endl;
}
FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
    std::cout << "FragTrap " << this->name << " copied." << std::endl;
    *this = other;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
    }
    return *this;
}
FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << this->name << " destroyed." << std::endl;   
}
void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << this->name << " is requesting a high five!" << std::endl;
}

