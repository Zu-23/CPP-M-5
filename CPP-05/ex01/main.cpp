#include "Form.hpp"
#include"Bureaucrat.hpp"

int main()
{
	{
		Bureaucrat biro1("biro1", 10);
		Form form1("form1", 40, 30);
		std::cout << "biro1 before signing" << std::endl;
		std::cout << biro1 << std::endl;
		biro1.signForm(form1);
		std::cout << "biro after signing" << std::endl; 
		std::cout << biro1 << std::endl;
	}
	{
		Bureaucrat biro2("biro2", 100);
		Form form2("form2", 40, 30);
		std::cout << "biro2 before signing" << std::endl;
		std::cout << biro2 << std::endl;
		biro2.signForm(form2);
		std::cout << "biro2 after signing" << std::endl; 
		std::cout << biro2 << std::endl;
	}
	
}