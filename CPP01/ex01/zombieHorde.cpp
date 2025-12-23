/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moraouf <moraouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 16:00:09 by moraouf           #+#    #+#             */
/*   Updated: 2025/12/23 16:06:25 by moraouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zombie.hpp"


Zombie* zombieHorde(int N , std::string name)
{
    if(N <= 0)
        return NULL;

    Zombie *zombies;

    zombies = new Zombie[N];

    for(int i = 0; i < N; i++)
    {
        zombies[i].setName(name);
    }
    return zombies;
}