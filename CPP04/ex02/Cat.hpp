/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moraouf <moraouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 17:31:18 by moraouf           #+#    #+#             */
/*   Updated: 2025/12/31 12:53:20 by moraouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP


#include "Animal.hpp"
#include <iostream>
#include "Brain.hpp"



class Cat : public Animal
{
    private:
        Brain* brain;
    public:
        Cat();
        ~Cat();
        Cat(const Cat& other);
        Cat& operator=(const Cat& other);
        void makeSound() const;
        std::string getType() const;
        Brain* getBrain() const;
};




#endif