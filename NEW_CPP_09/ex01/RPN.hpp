#ifndef RPN_HPP
#define RPN_HPP

#include<iostream>
#include<string>
parse_input(std::string line)
{
	std::string op = "+-/*";
   for(size_t i = 0; i < line.size(); i++)
   {
		if (!std::isspace(line[i]) && !std::isdigit(line[i] && op.find(line[i]) == std::string::npos))
   }

    
}

#endif