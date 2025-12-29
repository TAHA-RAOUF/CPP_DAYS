/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moraouf <moraouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 16:29:19 by moraouf           #+#    #+#             */
/*   Updated: 2025/12/29 16:30:22 by moraouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP



#include "ClapTrap.hpp"


class FragTrap : public ClapTrap
{
    public:
        FragTrap();
        FragTrap(const std::string& name);
        FragTrap(const FragTrap& other);
        FragTrap& operator=(const FragTrap& other);
        ~FragTrap();
        void highFivesGuys(void);
};

#endif