#include "Bureaucrat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Bureaucrat::Bureaucrat(std::string name, int grade): name(name), grade(grade)
{
	std::cout << "Bureaucrat constructor called " << this->name << std::endl;
	try
	{
		if (grade < 1)
			throw(Bureaucrat::GradeTooHighException());
		else if (grade > 150)
			throw(Bureaucrat::GradeTooLowException());
	}
	catch(Bureaucrat::GradeTooHighException& b)
	{
		std::cerr << b.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException& b)
	{
		std::cerr << b.what() << std::endl;
	}
}

Bureaucrat::Bureaucrat( const Bureaucrat & src ) : name(src.name), grade(src.grade)
{
	std::cout << "copy constructor called" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Bureaucrat::~Bureaucrat()
{
	std::cout << this->getName() << " got destroyed" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Bureaucrat &				Bureaucrat::operator=( Bureaucrat const & rhs )
{
	if ( this != &rhs )
	{
		this->grade = rhs.getGrade();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i )
{
	o << i.getName() << ", bureaucrat grade " << i.getGrade();
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/
void Bureaucrat::incrementGrade()
{
	std::cout << "incrementing grade" << std::endl;
	try
	{
		if (this->grade == 1)
			throw (Bureaucrat::GradeTooHighException());
	}
	catch(Bureaucrat::GradeTooHighException& b)
	{
		std::cerr << b.what() << std::endl;
		return ;
	}
	this->grade -= 1;
}

void Bureaucrat::decrementGrade()
{
	std::cout << "decrementing grade" << std::endl;
	try
	{
		if (this->grade == 150)
			throw (Bureaucrat::GradeTooLowException());	
	}
	catch(Bureaucrat::GradeTooLowException& b)
	{
		std::cerr << b.what() << std::endl;
		return ;
	}
	this->grade += 1;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}
const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/
std::string Bureaucrat::getName() const
{
	return (this->name);
}

int	Bureaucrat::getGrade() const
{
	return (this->grade);
}

/* ************************************************************************** */