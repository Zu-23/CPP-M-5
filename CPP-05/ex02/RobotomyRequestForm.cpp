#include "RobotomyRequestForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/
RobotomyRequestForm::RobotomyRequestForm() : Form("Robotomy Request Form", 72, 45)
{
	this->target = "defualt";
	std::cout << "robotomy default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) :Form("Robotomy Request Form", 72, 45), target(target)
{
	std::cout << "robotomy constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm & src ) : Form(src)
{
	std::cout << "robotomy copy constructor called" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Robotomy dectructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

RobotomyRequestForm &				RobotomyRequestForm::operator=( RobotomyRequestForm const & rhs )
{
	std::cout << "Robotomy copy assignment called" << std::endl;
    this->target = rhs.target;
    return *this;
}

std::ostream &			operator<<( std::ostream & o, RobotomyRequestForm const & i )
{
	 o << "robotomy name: " << i.getName() << " grade to sign " << i.getGradeSign()
	<<  "signed " << i.getSign() << " grade to execute " << i.getGradeExe() << std::endl;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/
void    RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (this->getSign() == false)
        throw Form::NotSignedException();
    else if (executor.getGrade() > this->getGradeExe())
        throw Form::GradeTooLowException();
    else
    {
        std::cout << "Drilling noises" << std::endl;
        srand(time(0));
        if (rand() % 2 == 0)
            std::cout << this->target << " has been robotomized successfully" << std::endl;
        else
            std::cout << this->target << " robotomization failed" << std::endl;
    }
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */