#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <string>
#include "AForm.hpp"

class PresidentialPardonForm : public Form
{
	private:
		std::string target;
	public:

		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm( PresidentialPardonForm const & src );
		~PresidentialPardonForm();
		PresidentialPardonForm &		operator=( PresidentialPardonForm const & rhs );
void 	execute(Bureaucrat const & executor) const;
};

std::ostream &			operator<<( std::ostream & o, PresidentialPardonForm const & i );

#endif /* ****************************************** PRESIDENTIALPARDONFORM_H */