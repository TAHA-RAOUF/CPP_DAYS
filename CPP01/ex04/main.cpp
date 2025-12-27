/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moraouf <moraouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 15:50:03 by moraouf           #+#    #+#             */
/*   Updated: 2025/12/24 17:23:37 by moraouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <fstream>


int main(int ac, char **av)
{
    if(ac != 4)
    {
        std::cerr << "Usage: " << av[0] << " <filename> <string1> <string2>" << std::endl;
        return 1;
    }
    std::string filename = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];
    if(s1.empty() || s2.empty())
    {
        std::cerr << "Error: string1 and string2 must not be empty" << std::endl;
        return 1;
    }
    std::ifstream file(filename.c_str());
    if(!file.is_open())
    {
        std::cerr << "Error: could not open file " << filename << std::endl;
        return 1; 
    }
    std::ofstream outfile((filename + ".replace").c_str());
    if(!outfile.is_open())
    {
        file.close();
        std::cerr << "Error: could not create output file" << std::endl;
        return 1;
    }
    std::string line;
    while(getline(file, line))
    {
        size_t pos = 0;
        while((pos = line.find(s1, pos)) != std::string::npos)
        {
            line.erase(pos, s1.length());
            line.insert(pos, s2);
            pos += s2.length();
        }
        outfile << line << std::endl;
    }
    file.close();
    outfile.close();
    return 0;
}

