#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <string>

class ShrubberyCreationForm
{

	private:
		std::string target;
	public:
		ShrubberyCreationForm(void);
		~ShrubberyCreationForm(void);
		ShrubberyCreationForm(const ShrubberyCreationForm &obj);
		ShrubberyCreationForm(std::string  &target);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &obj);
void    execute( const Bureaucrat& executor ) const;
};

#endif /* ******************************************* SHRUBBERYCREATIONFORM_H */