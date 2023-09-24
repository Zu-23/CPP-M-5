#include "RPN.hpp"
Rpn::Rpn()
{

}

Rpn::Rpn(const Rpn& obj)
{
	*this = obj;
}

Rpn& Rpn::operator=(const Rpn& obj)
{
	this->instk = obj.instk;
}

void Rpn::ft_perror(std::string str)
{
	std::cout << str << std::endl;
	exit(1);
}

void Rpn::calculate(std::stack<int> &di_stk, char oprt)
{
	int fst;
	int scnd;

	if (di_stk.empty())
		ft_perror("Error: bad expression");
	scnd = di_stk.top();
	di_stk.pop();
	if (di_stk.empty())
	{
		std::cout << "hola : " << scnd << std::endl;
		return ;
	}
	fst = di_stk.top();
	di_stk.pop();
	switch (oprt)
	{
	case '+':
		di_stk.push(fst + scnd);
		break;
	case '-':
		di_stk.push(fst - scnd);
		break;
	case '*':
		di_stk.push(fst * scnd);
		break;
	case '/':
		if (scnd == 0)
			ft_perror("Can't divide by 0");
		di_stk.push(fst / scnd);
		break;
	default:
		break;
	}
}

int Rpn::parse_expression(std::string expr)
{
	int digit = 0;
	std::stack<int> di_stk;
	for (size_t i = 0; i < expr.size(); i++)
	{
		if (std::isdigit(expr[i]))
		{
			if (++digit > 2)
				ft_perror("Error: bad expression");
			di_stk.push(expr[i] - '0');
		}
		else
		{
			if (digit == 0 && di_stk.size() != 2)
			{
				while (!di_stk.empty())
				{
					std::cout << "stk = " << di_stk.top() << std::endl;
					di_stk.pop();
				}
				ft_perror("Errrror");
			}
			digit = 0;
			calculate(di_stk, expr[i]);
		}
	}
		if (digit != 0)
			ft_perror("Error: bad expression");
	std::cout << "res = " << di_stk.top() << std::endl;
	return (0);
}

void Rpn::parse_input(std::string line)
{
	std::string op = "+-/*";
	std::string expr = "";
	size_t var;
   for(size_t i = 0; i < line.size(); i++)
   {
		var = op.find(line[i]);
		if (!std::isspace(line[i]) && !std::isdigit(line[i]) && var  == std::string::npos)
			ft_perror("Error: bad expression");
		else if (std::isdigit(line[i]) || var  != std::string::npos)
			expr += line[i];
   }
   if (expr.size() < 2)
		ft_perror("Error: bad expression");
	std::cout << expr << std::endl;
	parse_expression(expr);
}
