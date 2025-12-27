/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moraouf <moraouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 17:42:14 by moraouf           #+#    #+#             */
/*   Updated: 2025/12/23 18:05:52 by moraouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>


int main()
{
    std::string str = "HI THIS IS BRAIN";

    std::string* stringPTR = &str;
    std::string& stringREF = str;

    std::cout << "-----Memory address-----" << std::endl;
    std::cout << "Address of str       : " << &str << std::endl;
    std::cout << "Address in stringPTR : " << stringPTR << std::endl;
    std::cout << "Address of stringREF : " << &stringREF << std::endl;

    std::cout << "-----Value-----" << std::endl;
    std::cout << "Value of str       : " << str << std::endl;
    std::cout << "Value pointed by stringPTR : " << *stringPTR << std::endl;
    std::cout << "Value pointed by stringREF : " << stringREF << std::endl;

    return 0;
}