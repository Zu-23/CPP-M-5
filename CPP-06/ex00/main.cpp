#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
    if (ac == 1 || ac > 2)
		print("wrong number of arguments\n");
	else
	{
		if (ScalarConverter::convert(av[1]))
		{
            print("Enter a valid data type: Int - Char - Float - Double - +inf - -inf - nan - nanf\n");
			return 0;
		}
    }
}