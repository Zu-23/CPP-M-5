#include "Bureaucrat.hpp"


int main()
{
    Bureaucrat tooHigh("tooHigh", 0);
	Bureaucrat tooLow("tooLow", 160);
	Bureaucrat valid("valid", 100);
	valid.incrementGrade();
	valid.decrementGrade();
    Bureaucrat max("max", 1);
    max.incrementGrade();
	std::cout << max << std::endl;


}