/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moraouf <moraouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 15:08:06 by moraouf           #+#    #+#             */
/*   Updated: 2025/12/23 17:10:30 by moraouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zombie.hpp"


int main()
{
    int N = 10;

    Zombie *Zombies = zombieHorde(N,"black_wolf");
    
    for(int i = 0;i < N; i++)
    {
        Zombies[i].announce();
    }

    delete[] Zombies;
    return 0;
}