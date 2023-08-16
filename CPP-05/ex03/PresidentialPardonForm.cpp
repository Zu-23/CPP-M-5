#include "PresidentialPardonForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PresidentialPardonForm::PresidentialPardonForm() : Form("Presidential Pardon Form", 25, 5)
{
	this->target = "default";
	std::cout << "presendential default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("Presidential Pardon Form", 25, 5), target(target)
{
	std::cout << "presendential constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm & src ) : Form(src)
{
	std::cout << "presendential copy constructor called" << std::endl;

}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "presendential  deconstructor called" << std::endl;
}
/*
** --------------------------------- OVERLOAD ---------------------------------
*/
PresidentialPardonForm &				PresidentialPardonForm::operator=( PresidentialPardonForm const & rhs )
{
	this->target = rhs.target;
	std::cout << "presendential default copy assignment called" << std::endl;
	return *this;
}

std::ostream &			operator<<( std::ostream & o, PresidentialPardonForm const & i )
{
	o << "presendtial name: " << i.getName() << " grade to sign " << i.getGradeSign()
	<<  "signed " << i.getSign() << " grade to execute " << i.getGradeExe() << std::endl;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void 	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (getSign() == false)
		throw (Form::NotSignedException());
	else if (executor.getGrade() > getGradeExe())
		throw (Form::GradeTooLowException());
	else
		std::cout << this->target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */