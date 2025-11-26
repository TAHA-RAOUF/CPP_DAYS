

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <Contact.hpp>
# include <iostream>

class  Phonebook
{
private:
    Contact contact[8];
    int count;

public:
     Phonebook(void);
     void   get_info(void);
     void   set_info(void);
     void   show_prompt(void);
};

#endif