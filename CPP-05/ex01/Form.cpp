#include "Form.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Form::Form(void): name("default"), gradeSign(69), gradeExe(69), sign(false) 
{
	std::cout << "Form default constructor called" << std::endl;
}


Form::Form(std::string name, int grSign, int grExe) : name(name), gradeSign(grSign), gradeExe(grExe), sign(false)
{
	try
	{
		if (this->gradeSign < 1 || this->gradeExe < 1)
			throw GradeTooHighException();
		else if (this->gradeSign > 150 || this->gradeExe > 150)
			throw GradeTooLowException();
	}
	catch (GradeTooHighException& b)
	{
		std::cerr << b.what() << std::endl;
	}
	catch (GradeTooLowException& b)
	{
		std::cerr << b.what() << std::endl;
	}
	std::cout << "Form constructor called " << this->name << std::endl;
}

Form::Form( const Form & src ) : name(src.name), gradeSign(src.gradeSign), gradeExe(src.gradeExe), sign(src.sign)
{
	std::cout << "Form copy constructor got called" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Form::~Form()
{
	std::cout << "Form destructor got called " << this->name << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Form& Form::operator=( Form const & rhs )
{
	if ( this != &rhs )
	{
		this->sign = rhs.sign;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Form const & i )
{
	o << "Form name: " << i.getName() << " grade to sign " << i.getGradeSign()
	<<  "signed " << i.getSign() << " grade to execute " << i.getGradeExe() << std::endl;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	Form::beSigned(Bureaucrat &b)
{
	if (this->getGradeSign() < b.getGrade())
		throw GradeTooLowException();
	else if (this->getGradeSign() >= b.getGrade())	
		this->sign = true;
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string Form::getName() const
{
	return(this->name);
}

int	Form::getGradeSign() const
{
	return (this->gradeSign);
}

int Form::getGradeExe() const
{
	return(this->gradeExe);
}

bool Form::getSign() const
{
	return (this->sign);
}

/* ************************************************************************** */
