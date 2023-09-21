#include <iostream>
#include<string>

void parse_input(std::string line)
{
	std::string op = "+-/*";
    std::string expr = "";
    size_t var;
   for(size_t i = 0; i < line.size(); i++)
   {
        var = op.find(line[i]);
        if (!std::isspace(line[i]) && !std::isdigit(line[i]) && var  == std::string::npos)
        {
            std::cout << line[i] <<  " bad input" << std::endl;
            return ;
        }
        else if (std::isdigit(line[i]) || var  != std::string::npos)
        {
            std::cout << "line[i] = " << line[i] << std::endl;
            expr += line[i];
        }
   }
    std::cout << expr << std::endl;
}

int main()
{
    parse_input("1-1-");
}