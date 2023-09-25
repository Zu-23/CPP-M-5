#ifndef RPN_HPP
#define RPN_HPP

#include<iostream>
#include<string>
#include<stack>

class Rpn
{
   private:
		void calculate(std::stack<int> &di_stk, std::stack<char> &oprt);
		int parse_expression(std::string expr);
   public:
		 Rpn();
		 void parse_input(std::string line);
		 Rpn(const Rpn &obj);
		 ~Rpn();
	  Rpn& operator=(const Rpn &obj);
};

 void ft_perror(std::string str);
#endif