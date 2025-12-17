/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moraouf <moraouf@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 18:58:36 by moraouf           #+#    #+#             */
/*   Updated: 2025/12/17 21:22:42 by moraouf        ###   ########.fr       */
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
        {
            std::cout << "Exiting PhoneBook. Goodbye!" << std::endl;
            break;
        }        
        Book.show_prompt();
    }
}

