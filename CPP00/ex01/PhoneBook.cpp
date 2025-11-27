/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moraouf <moraouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 19:28:33 by moraouf           #+#    #+#             */
/*   Updated: 2025/11/27 18:00:32 by moraouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"


PhoneBook::PhoneBook(void)
{
	count = 0;
	full = false;
}


void PhoneBook::display_contacts(void)
{
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << "|  Index   |First Name| Last Name| Nickname |" << std::endl;
	std::cout << "-------------------------------------------" << std::endl;
	for(int i = 0; i < this->count; i++)
	{
		PhoneBook::contact[i].get_contact_info();
	}
	std::cout << "-------------------------------------------" << std::endl;
}

void PhoneBook::get_info(void)
{
	if(this->count == 0 && this->full == false)
	{
		std::cout << "PhoneBook is empty. Please add contacts first." << std::endl;
		return ;
	}
	this->display_contacts();
	while(true)
	{
		std::string input;
		std::cout << "Searching contacts..." << std::endl;
		std::cout << "can you please enter the index of the contact you want to see details about (1 to 8): ";
		std::getline(std::cin, input);
		if(std::cin.eof() == true)
		{
			std::cout << "EOF detected. Exiting" << std::endl;
			exit(0);
		}
		if(input.length() != 1 || input[0] < '1' || input[0] > '8')
		{
			std::cout << "Invalid index. Please enter a number between 1 and 8." << std::endl;
			continue ;
		}
		
		
	}
}
void PhoneBook::set_info(void)
{
	std::string input;
	

	if(this->full == false)
	{
		std::cout << "This is your contact number " << this->count + 1 << std::endl;
		this->contact[this->count].set_contact_info();
		if(this->count == 7)
			this->full = true;
		else
			this->count++;
	}
	else 
	{
		std::cout << "PhoneBook is full, the new contact will replace the oldest one." << std::endl;
		std::cout << "if you want to continue type YES else type NO" << std::endl;
		std::getline(std::cin, input);
		if(std::cin.eof() == true)
		{
			std::cout << "EOF detected. Exiting" << std::endl;
			exit(0);
		}
		if(input == "YES")
		{
			this->count = (this->count + 1) % 8;
			std::cout << "This is your contact number " << this->count + 1 << std::endl;
		}
		else
		{
			std::cout << "Contact not added." << std::endl;
			return ;
		}
	}
}


void	PhoneBook::show_prompt(void)
{
	std::cout << "\033[KEnter your command [ADD, SEARCH, EXIT]:" << std::endl;
}
