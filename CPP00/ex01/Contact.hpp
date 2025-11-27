
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
};

#endif
