/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moraouf <moraouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 15:06:52 by moraouf           #+#    #+#             */
/*   Updated: 2025/12/31 14:57:30 by moraouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{

    std::cout << "===== POLYMORPHISM TEST =====" << std::endl;

    const Animal *a = new Dog();
    const Animal *b = new Cat();
    // const Animal c ; // to test abstract class instantiation error
    a->makeSound(); // must bark
    b->makeSound(); // must meow

    delete a;
    delete b;

    std::cout << "\n===== DEEP COPY TEST =====" << std::endl;

    Dog original;
    original.getBrain()->setIdea(0, "I love bones");

    Dog copy = original; // copy constructor

    copy.getBrain()->setIdea(0, "I love fish");
    std::cout << "Original idea: " << original.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copy idea: " << copy.getBrain()->getIdea(0) << std::endl;

    std::cout << "\n===== ARRAY OF ANIMALS =====" << std::endl;

    const int size = 2;
    Animal *animals[size];

    for (int i = 0; i < size; i++)
    {
        if (i % 2 == 0)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }
    for (int i = 0; i < size; i++)
    {
        animals[i]->makeSound();
    }
    for (int i = 0; i < size; i++)
    {
        delete animals[i];
    }

    return 0;
}