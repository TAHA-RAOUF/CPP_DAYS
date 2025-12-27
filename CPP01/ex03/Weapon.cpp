/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moraouf <moraouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 18:19:49 by moraouf           #+#    #+#             */
/*   Updated: 2025/12/23 18:24:20 by moraouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"



Weapon::Weapon(std::string type)
{
    this->type = type;
}

const std::string& Weapon::getType() const
{
    return this->type;
}

void Weapon::setType(std::string type)
{
    this->type = type;
}
