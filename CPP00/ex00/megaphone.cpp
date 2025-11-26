#include <iostream>


// int main(int ac, char **av)
// {
//     int i = 1;
//     int j = 0;

//     if(ac == 1)
//         std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
//     else
//     {
//         while(av[i])
//         {
//             j = 0;
//             while(av[i][j])
//             {
//                 if(av[i][j] >= 'a' && av[i][j] <= 'z')
//                     std::cout << (char)toupper(av[i][j]);
//                 else    
//                     std::cout << av[i][j];
//                 j++;
//             }
//             i++;
//         }
//         std::cout << std::endl;
//     }
// }


int main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }

    for (int i = 1; i < argc; ++i)
    {
        for (int j = 0; argv[i][j] != '\0'; ++j)
        {
            unsigned char ch = static_cast<unsigned char>(argv[i][j]);
            if (std::isprint(ch))
                std::cout << static_cast<char>(std::toupper(ch));
        }
    }
    std::cout << std::endl;
    return 0;
}