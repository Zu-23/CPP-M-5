#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include<string>
#include<cstdlib>
#include<cerrno>
#include<climits>
#include<cmath>
#include<cfloat>
#include<iomanip>

class ScalarConverter
{

	private:
		std::string num;
	public:

		ScalarConverter();
		ScalarConverter( ScalarConverter const & src );
		~ScalarConverter();
static int	convert(std::string num);
static int 	CheckChar(std::string num);
static int 	CheckFloat(std::string num);
static int 	CheckInt(std::string num);
static int 	CheckDouble(std::string num);
static void 	conv_to_char(std::string num, std::string hay);
static void 	conv_to_float(std::string num, std::string hay);
static void 	conv_to_double(std::string num, std::string hay);
static void 	conv_to_int(std::string num, std::string hay);


		ScalarConverter &		operator=( ScalarConverter const & rhs );

	private:

};
void	print(std::string str);
// std::ostream &			operator<<( std::ostream & o, ScalarConverter const & i );

#endif /* ************************************************* SCALARCONVERTER_H */