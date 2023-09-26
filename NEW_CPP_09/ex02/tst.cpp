#include<iostream>
#include<ctime>
#include<unistd.h>
#include<cstdlib>
#include<sys/time.h>
#include<vector>
#include<list>

#include <iostream>
#include <vector>
#include<deque>
#include<algorithm>

void ft_perror(std::string str)
{
    std::cout << str << std::endl;
    exit(1);
}

void validNum(char **av, int ac)
{
    int digit = 0;
	for (int i = 1 ; i < ac; i++)
	{
		std::string str = av[i];
        for (size_t j = 0; j < str.size(); j++)
        {
            if (std::isdigit(str[j]))
            {
                digit = 1;
                break ;
            }
        }
        if (digit == 0)
            ft_perror("Invalid input");
		for (size_t j = 0; j < str.size(); j++)
		{
			if (!std::isspace(str[j]) && !std::isdigit(str[j]))
				ft_perror("Invalid input");
		}
        digit = 0;
	}
}


int main(int ac, char **av)
{
    validNum(av, ac);
}
