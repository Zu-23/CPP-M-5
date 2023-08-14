#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("shrubbery creation", 145, 137)
{
	std::cout << "ShrubberyCreationForm Default Constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string &target): AForm(145, 137, "Shrubbery Creation"), target(target)
{
	std::cout << "ShrubberyCreationForm Constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj): AForm(obj), target(obj.target)
{
	std::cout << "ShrubberyCreationForm Copy Constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "ShrubberyCreationForm Destructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj)
{
	this->target = obj.target;
	std::cout << "ShrubberyCreationForm Copy Assignment called" << std::endl;
	return (*this);
}
