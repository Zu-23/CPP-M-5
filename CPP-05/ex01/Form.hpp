#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;
class Form
{

	private:
		const std::string name;
		const	int		  gradeSign;
		const	int		  gradeExe;
		bool			  sign;
	public:
		Form();
		Form(std::string name, int grSign, int grExe);
		Form( Form const & src );
		~Form();
		Form &		operator=( Form const & rhs );
		std::string getName() const;
		int			getGradeSign() const;
		int			getGradeExe() const;
		bool		getSign() const;
		void		beSigned(Bureaucrat& b);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("FORM: Grade too high");
				}
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("FORM: Grade too low");
				}
		};

};

std::ostream &			operator<<( std::ostream & o, Form const & i );

#endif /* ************************************************************ FORM_H */