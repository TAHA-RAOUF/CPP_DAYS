/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moraouf <moraouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 18:58:36 by moraouf           #+#    #+#             */
/*   Updated: 2025/11/27 16:51:38 by moraouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PhoneBook.hpp"
# include "Contact.hpp"


int main()
{
    PhoneBook Book;
    std::string prompt;
    Book.show_prompt();

    while(1)
    {
        std::getline(std::cin, prompt);
        if (std::cin.eof())
            break ;
        if (prompt == "ADD")
            Book.set_info();
        else if (prompt == "SEARCH")
            Book.get_info();
        if (prompt == "EXIT")
            break ;
        Book.show_prompt();       
    }
}