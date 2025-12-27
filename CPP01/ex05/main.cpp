/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moraouf <moraouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 17:33:51 by moraouf           #+#    #+#             */
/*   Updated: 2025/12/24 18:08:56 by moraouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp" 

void Harl::complain( std::string level )
{
    void (Harl::*funcsptrs[])() = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };
    std::string levels[] = {
        "DEBUG",
        "INFO",
        "WARNING",
        "ERROR"
    };
    for (int i = 0; i < 4; i++)
    {
        if(level == levels[i])
            (this->*funcsptrs[i])();
    }  
}


int main()
{
    Harl harl;
    harl.complain("DEBUG");
    harl.complain("INFO");
    harl.complain("WARNING");
    harl.complain("ERROR");
    return 0;
}