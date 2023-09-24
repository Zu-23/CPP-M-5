#include "PmergeMe.hpp"


int main(int ac, char **av)
{
    try
    {
        if (ac != 2)
            ft_perror("Invalid argument");
        else
        {
            PmergeMe mrg;
            mrg.parse_input(av);
        }

    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}