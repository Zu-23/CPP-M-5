#include "Intern.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Intern::Intern()
{
	std::cout << "Inter default constructor called" << std::endl;
}

Intern::Intern( const Intern & src )
{
	std::cout << "Inter copy constructor called" << std::endl;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Intern::~Intern()
{
	std::cout<< "Inter deconstructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Intern &				Intern::operator=( Intern const & rhs )
{
	(void)rhs;
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/
Form *Intern::makeForm(std::string const & formName, std::string target)
{
	int 	i;

	i = 0;
	std::string forms[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	while (i < 3)
	{
		if (forms[i] == formName)
			break;
		i++;
	}
	switch (i)
	{
		case 0:
			return (new RobotomyRequestForm(target));
		case 1:
			return (new PresidentialPardonForm(target));
		case 2:
			return (new ShrubberyCreationForm(target));
		default:
			std::cout << "Unknown Form" << std::endl;
			break;
	}
	return (NULL);
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */