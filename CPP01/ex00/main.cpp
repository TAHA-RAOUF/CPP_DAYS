/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moraouf <moraouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 19:31:00 by moraouf           #+#    #+#             */
/*   Updated: 2025/12/22 18:10:33 by moraouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

int main()
{
    std::cout << "----Stack Zombie----" << std::endl;
    ramdomChump("Black_wolf");
    std::cout << "----Heap Zombie----" << std::endl;
    Zombie* zombie = newZombie("Taha");
    zombie->announce();
    delete zombie;
    return (0);    
}