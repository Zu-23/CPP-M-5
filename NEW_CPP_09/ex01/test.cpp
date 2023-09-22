#include <iostream>
#include<string>
#include<stack>


void ft_perror(std::string str)
{
	std::cout << str << std::endl;
	exit(1);
}
int parse_expression(std::string expr)
{
	int digit = 0;
	int oprt = 0;
	std::stack<int> di_stk;
	char ch_oprt;
	for (size_t i = 0; i < expr.size(); i++)
	{
		if (std::isdigit(expr[i]))
		{
			digit++;
			di_stk.push(expr[i] - '0');
		}
		else
		{
			if (digit)
			{
				if (digit )
				if (digit >= 1 && digit <= 3)
			}
			else
				error;
		}
		// if (digit != 0)
		// 	ft_perror("Error: bad expression");
		// // calculate(di_stk, ch_oprt);
	}
	return (0);
}

void parse_input(std::string line)
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

int main()
{
	parse_input("     1 4 / 2  ");
}