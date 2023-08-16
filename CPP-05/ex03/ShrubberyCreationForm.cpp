#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("shrubbery creation", 145, 137)
{
	this->target = "default Joe";
	std::cout << "ShrubberyCreationForm Default Constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): Form("Shrubbery Creation",145, 137), target(target)
{
	std::cout << "ShrubberyCreationForm Constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj): Form(obj), target(obj.target)
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

std::ostream &			operator<<( std::ostream & o, ShrubberyCreationForm const & i )
{
	o << "shrubbery name: " << i.getName() << " grade to sign " << i.getGradeSign()
	<<  "signed " << i.getSign() << " grade to execute " << i.getGradeExe() << std::endl;
	return o;
}


void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (this->getSign() == false)
		throw (Form::NotSignedException());
	if (executor.getGrade() > this->getGradeExe())
		throw (Form::GradeTooLowException());
    std::string fstr = this->target + "_shrubbery";
 	std::ofstream file(fstr.c_str());

 	file << "               _{\\ _{\\{\\/}/}/}__" << std::endl;
    file << "             {/{/\\}{/{/\\}(\\}{/\\} _" << std::endl;
    file << "            {/{/\\}{/{/\\}(_)}{/{/\\}  _" << std::endl;
    file << "         {\\{/(/}\\}{/{/\\}\\}{/){/\\}\\} /\\}" << std::endl;
    file << "        {/{/(_)/}{\\{/)/}{\\(_){/}/}/}/}" << std::endl;
    file << "       _{\\{/{/{\\{/{/(_)/}/}/}{\\(/}/}/}" << std::endl;
    file << "      {/{/{\\{\\{(/}{\\{\\/}/}{\\}(_){\\/}\\}" << std::endl;
    file << "      _{\\{/{\\{/(_)/}/}{/{/{/\\}\\)(\\}{/\\}" << std::endl;
    file << "     {/{/{\\{(/}{/{\\{\\{\\/})/}{\\(_)/}/}\\}" << std::endl;
    file << "      {\\{\\/}(_){\\{\\{\\/}/}(_){\\/}{\\/}/)(/}" << std::endl;
    file << "       {/{\\{\\/}{/{\\{\\{\\/}/}{\\{\\/}/}\\}(_)" << std::endl;
    file << "      {/{\\{\\/}{/){\\{\\{\\/}/}{\\{\\(/}/}\\}/}" << std::endl;
    file << "       {/{\\{\\/}(_){\\{\\{\\(/}/}{\\(_)/}/}\\}" << std::endl;
    file << "         {/({/{\\{/{\\{\\/}(_){\\/}/}\\}/}(\\}" << std::endl;
    file << "          (_){/{\\/}{\\{\\/}/}{\\{\\)/}/}(_)" << std::endl;
    file << "            {/{/{\\{\\/}{/{\\{\\{\\(_)/}" << std::endl;
    file << "             {/{\\{\\{\\/}/}{\\{\\\\}/}" << std::endl;
    file << "              {){/ {\\/}{\\/} \\}\\}" << std::endl;
    file << "              (_)  \\.-'.-/" << std::endl;
    file << "          __...--- |'-.-'| --...__" << std::endl;
    file << "   _...--\"   .-'  |'-.-'|  ' -.  \"\"--..__" << std::endl;
    file << " -\"    ' .  . '   |.'-._| '  . .  '   jro" << std::endl;
    file << " .  '-  '    .--'  | '-.'|    .  '  . '" << std::endl;
    file << "          ' ..     |'-_.-|" << std::endl;
    file << "  .  '  .       _.-|-._ -|-._  .  '  ." << std::endl;
    file << "              .'   |'- .-|   '." << std::endl;
    file << "  ..-'   ' .  '.   `-._-_.'   .'  '  - ." << std::endl;
    file << "   .-' '        '-._______.-'     '  ." << std::endl;
    file << "        .      ~," << std::endl;
    file.close();
}