#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
#include "AForm.hpp"

class Form;
class Bureaucrat
{
	private:
			class GradeTooHighException;
			class GradeTooLowException;
			const std::string		name;
			int						grade;
			Bureaucrat();
	
	public:
			Bureaucrat(std::string name, int grade);
			Bureaucrat( Bureaucrat const & src );
			~Bureaucrat();
			Bureaucrat &operator=( Bureaucrat const & rhs );
void		incrementGrade(void);
void		decrementGrade(void);
int			getGrade() const;
void		signForm(Form &b);
void		executeForm(Form const & form);
std::string	getName() const;
};

class Bureaucrat::GradeTooHighException : public std::exception
 {
		public:
			virtual const char* what() const throw ();
 };

class Bureaucrat::GradeTooLowException : public std::exception
 {
		public:
			virtual const char* what() const throw();
 };

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i );

#endif /* ****************************************************** BUREAUCRAT_H */