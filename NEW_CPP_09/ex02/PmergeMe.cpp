#include "PmergeMe.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe( const PmergeMe & src )
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PmergeMe::~PmergeMe()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

PmergeMe &				PmergeMe::operator=( PmergeMe const & rhs )
{
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}



/*
** --------------------------------- METHODS ----------------------------------
*/
void PmergeMe::ft_perror(std::string str)
{
	std::cout << str << std::endl;
	exit(1);
}

int PmergeMe::validNum(char **av, int ac)
{
	for (size_t i = 1 ; i < ac; i++)
	{
		std::string str = av[i];
		for (size_t j = 0; j < str.size(); j++)
		{
			if (!std::isspace(str[j]) && !std::isdigit(str[j]))
				ft_perror("Invalid input");
		}

	}
}

void PmergeMe::parse_input(char **av, int ac)
{
	std::istringstream s()
	validNum(av, ac);// test with 2 digits

	
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */