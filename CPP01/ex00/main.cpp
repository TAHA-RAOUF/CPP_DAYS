/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moraouf <moraouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 19:31:00 by moraouf           #+#    #+#             */
/*   Updated: 2025/12/22 17:39:16 by moraouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

int main()
{
    ramdomChump("Black_wolf");
    Zombie* zombie = newZombie("Taha");
    zombie->announce();
    delete zombie;
    return (0);    
}