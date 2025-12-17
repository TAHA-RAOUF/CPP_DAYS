/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moraouf <moraouf@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 21:53:10 by moraouf         #+#    #+#             */
/*   Updated: 2025/12/17 21:53:11 by moraouf        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <cstdlib>


class Contact
{
    static std::string fields_name[5];
    std::string fields_value[5];
public:
    Contact(void);
    void set_contact_info(void);
    void get_contact_info(void);
    void display_full_contact(void);
};

#endif
