/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moraouf <moraouf@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 16:27:06 by moraouf           #+#    #+#             */
/*   Updated: 2025/12/17 21:51:03 by moraouf        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string Contact::fields_name[] = {
    "First Name",
    "Last Name",
    "Nickname",
    "Phone Number",
    "Darkest Secret"
};

Contact::Contact(void){}


void Contact::get_contact_info(void)
{
    for (int i = 0; i < 3; i++)
    {
        std::string display_value = fields_value[i];
        if (display_value.length() > 10)
        {
            display_value = display_value.substr(0, 9) + ".";
        }
        std::cout << "|";
        std::cout.width(10);
        std::cout << display_value;
    }
    std::cout << "|" << std::endl;
}

void Contact::display_full_contact(void)
{
    for (int i = 0; i < 5; i++)
    {
        std::cout << fields_name[i] << ": " << fields_value[i] << std::endl;
    }
}

void Contact::set_contact_info(void) {
    for (int i = 0; i < 5; i++)
    {
        std::cout << "Enter " << fields_name[i] << ": ";
        std::getline(std::cin, fields_value[i]);
        while(!std::cin || this->fields_value[i].empty())
        {
            if(!std::cin)
            {
                std::cout << "EOF detected. Exiting" << std::endl;
                return;
            }
            if(this->fields_value[i].empty())
            {
                std::cout << fields_name[i] << " cannot be empty. Please enter again: ";
                std::getline(std::cin, fields_value[i]);
            }
        }
    }
    std::cout << "Contact added successfully!" << std::endl;
}

