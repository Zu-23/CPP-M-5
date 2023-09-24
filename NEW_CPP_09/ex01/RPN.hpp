#ifndef RPN_HPP
#define RPN_HPP

#include<iostream>
#include<string>
#include<stack>

class Rpn
{
   private:
      std::stack<int> instk;
      void ft_perror(std::string str);
      void calculate(std::stack<int> &di_stk, char oprt);
      int parse_expression(std::string expr);
      void parse_input(std::string line);
   public:
      Rpn();
      Rpn(const Rpn &obj);
      ~Rpn();
   Rpn& operator=(const Rpn &obj);
};

#endif