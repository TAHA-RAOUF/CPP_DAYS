

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>
# include <cstdlib>

class  PhoneBook
{
private:
    Contact contact[8];
    int count;
    int full;

public:
     PhoneBook(void);
     void   get_info(void);
     void   set_info(void);
     void   show_prompt(void);
     void   display_contacts(void);
};

#endif