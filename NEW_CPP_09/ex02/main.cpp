#include "PmergeMe.hpp"

//BRING BACK THE FLAGS
int main(int ac, char **av)
{
    try
    {
        PmergeMe mrg;
        mrg.parse_input(av, ac);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}