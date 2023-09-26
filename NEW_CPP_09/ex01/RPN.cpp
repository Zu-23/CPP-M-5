/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhaddoum <zhaddoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 23:51:22 by zhaddoum          #+#    #+#             */
/*   Updated: 2023/09/26 17:32:35 by zhaddoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	(void)obj;
	return *this;
}

Rpn::~Rpn()
{}

void ft_perror(std::string str)
{
	std::cout << str << std::endl;
	exit(1);
}

void Rpn::calculate(std::stack<int> &di_stk, std::stack<char> &oprt)
{
	int fst;
	int scnd;

	if (di_stk.empty())
	{
		ft_perror("Error: bad expression");
	}
	scnd = di_stk.top();
	di_stk.pop();
	if (di_stk.empty())
	{
		ft_perror("Error: bad expression");
		exit(1);
	}
	fst = di_stk.top();
	di_stk.pop();
	switch (oprt.top())
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
	std::stack<int> di_stk;
	std::stack<char> oprt;
	for (size_t i = 0; i < expr.size(); i++)
	{
		if (std::isdigit(expr[i]))
			di_stk.push(expr[i] - '0');
		else
		{
			oprt.push(expr[i]);
			calculate(di_stk, oprt);
			oprt.pop();
		}
	}
	if (di_stk.size() != 1 || oprt.size() != 0)
		ft_perror("Error: bad expression");
	std::cout << di_stk.top() << std::endl;
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
		if (var != std::string::npos && line[i + 1] != '\0' && line[i + 1] != ' ')
			ft_perror("Error: bad expression");
		if (!std::isspace(line[i]) && !std::isdigit(line[i]) && var  == std::string::npos)
			ft_perror("Error: bad expression");
		else if (std::isdigit(line[i]) && line[i + 1] != '\0' && line[i + 1] != ' ')
			ft_perror("Error: bad expression");
		else if (var != std::string::npos && line[i + 1] != '\0' && std::isdigit(line[i + 1]))
			ft_perror("Error: bad expression");
		else if (std::isdigit(line[i]) || var  != std::string::npos)
			expr += line[i];
   }
   if (expr.size() == 1)
   {
		std::cout << expr << std::endl;
		exit(1);
   }
		
	parse_expression(expr);
}
