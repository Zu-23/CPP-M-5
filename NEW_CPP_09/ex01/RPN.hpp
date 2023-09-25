/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhaddoum <zhaddoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 23:51:26 by zhaddoum          #+#    #+#             */
/*   Updated: 2023/09/25 23:51:27 by zhaddoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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