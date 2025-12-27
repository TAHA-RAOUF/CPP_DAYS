/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moraouf <moraouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 18:16:05 by moraouf           #+#    #+#             */
/*   Updated: 2025/12/23 18:24:29 by moraouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP


#include <iostream>



class Weapon
{
    private:
        std::string type;
    public:
        Weapon( std::string type );
        const std::string& getType() const;
        void    setType(std::string type);
};


#endif