#include "RPN.hpp"


int main(int ac, char **av)
{
    if (ac != 2)
        ft_perror("Invalid number of arguments");
    else
    {
        Rpn obj;
        obj.parse_input(av[1]);
    }
}