#include "PmergeMe.hpp"


int main(int ac, char **av)
{
    if (ac != 2)
        ft_perror("Invalid argument");
    else
    {
        PmergeMe mrg;
        mrg.parse_input(av);
    }

}