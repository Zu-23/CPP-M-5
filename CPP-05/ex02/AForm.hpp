#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"
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
		virtual ~Form();
		int			getGradeSign() const;
std::string 		getName() const;
		int			getGradeExe() const;
		bool		getSign() const;
		void		beSigned(Bureaucrat& b);


		Form&			operator=( Form const & rhs );
		virtual void    execute( const Bureaucrat& executor ) const = 0;

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

		class NotSignedException : public std::exception
		{
			public:
				virtual const char* what() const throw() 
				{ 
					return ("FORM: form is not signed"); 
				}
    };

};

std::ostream &			operator<<( std::ostream & o, Form const & i );

#endif /* ************************************************************ FORM_H */