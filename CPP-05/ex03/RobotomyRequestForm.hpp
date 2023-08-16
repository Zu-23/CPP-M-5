#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <string>
#include <cstdlib>
#include <ctime>
#include "AForm.hpp"
class RobotomyRequestForm : public Form
{
	private:
		std::string target;
	public:

		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm( RobotomyRequestForm const & src );
		~RobotomyRequestForm();
void    execute(Bureaucrat const & executor) const;

		RobotomyRequestForm &		operator=( RobotomyRequestForm const & rhs );


};

std::ostream &			operator<<( std::ostream & o, RobotomyRequestForm const & i );

#endif /* ********************************************* ROBOTOMYREQUESTFORM_H */