#include "ScalarConverter.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter( const ScalarConverter & src )
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ScalarConverter::~ScalarConverter()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ScalarConverter &				ScalarConverter::operator=( ScalarConverter const & rhs )
{
	(void)rhs;
	return *this;
}

// std::ostream &			operator<<( std::ostream & o, ScalarConverter const & i )
// {
// 	//o << "Value = " << i.getValue();
// 	return o;
// }


/*
** --------------------------------- METHODS ----------------------------------
*/
void	print(std::string str)
{
	std::cout << str;
}

void ScalarConverter::conv_to_char(std::string num, std::string hay)
{

	double res;
	char *end;

	print("char: ");
	if (hay.find(num) != std::string::npos)
		print("impossible\n");
	else if (num.length() == 1 && isalpha(num[0]))
	{
		if (!isprint(num[0]))
			print("Non Displayable\n");
		else
			std::cout << static_cast<char>(num[0]) << std::endl;
	}
	else
	{
		res = strtod(num.c_str(), &end);
		if ((errno == ERANGE && (res == HUGE_VAL || res == -HUGE_VAL)) || res > 255 || res < 0)
			print("Impossible\n");
		else if (!isprint(static_cast<char>(res)))
			print("Non displayable 2\n");
		else
			std::cout << static_cast<char>(res) << std::endl;
	}
}

void ScalarConverter::conv_to_int(std::string num, std::string hay)
{
	double res;
	char *end;

	print("int: ");
	if (hay.find(num) != std::string::npos)
		print("impossible\n");
	else if (num.length() == 1 && !isdigit(num[0]))
			std::cout << static_cast<int>(num[0]) << std::endl;
	else
	{
		res = strtod(num.c_str(), &end);
		if ((errno == ERANGE || res == HUGE_VAL || res == -HUGE_VAL || res > INT_MAX || res < INT_MIN))
			print("Impossible\n");
		else
			std::cout << static_cast<int>(res) << std::endl;
	}
}

void ScalarConverter::conv_to_float(std::string num, std::string hay)
{
	double res;
	char *end;

	print("float: ");
	if (hay.find(num) != std::string::npos)
	{
		if ((num.length() < 5 && num[num.length() - 1] == 'f') || num == "nan")
		{
			// print ("inside float\n ");
			if (num != "nanf")
				print(num + "f\n");
			else
				print("nanf\n");
		}
		else
			print(num + "\n");
	}
	else if (num.length() == 1 && !isdigit(num[0]))
			std::cout << std::fixed << std::setprecision(1) << static_cast<float>(num[0]) << "f" << std::endl;
	else
	{
		res = strtod(num.c_str(), &end);
		if ((errno == ERANGE && (res == HUGE_VAL || res == -HUGE_VAL) && res > FLT_MAX && res < -FLT_MIN))
			print("Impossible\n");
		else
			std::cout  << std::fixed << std::setprecision(1) << static_cast<float>(res) << "f" << std::endl;
	}
}

void ScalarConverter::conv_to_double(std::string num, std::string hay)
{
	double res;
	char *end;

	print("double: ");
	if (hay.find(num) != std::string::npos)
	{
		if (num.length() == 5 && num[num.length() - 1] == 'f')
				print(num.substr(0, num.length() - 1) + "\n");
		else
		{
			if (num == "nanf")
				print("nan\n");
			else
				print(num + "\n");
		}
	}
	else if (num.length() == 1 && !isdigit(num[0]))
			std::cout << std::fixed << std::setprecision(1) << static_cast<double>(num[0]) << std::endl;
	else
	{
		res = strtod(num.c_str(), &end);
		if ((errno == ERANGE || res == HUGE_VAL || res == -HUGE_VAL))
			print("Impossible\n");
		else
			std::cout  << std::fixed << std::setprecision(1) << static_cast<double>(res) << std::endl;
	}
}

 int ScalarConverter::convert(std::string num)
{
	int i;

	i = 0;
	int (*FooPtr[4])(std::string) = {CheckChar, CheckDouble, CheckInt, CheckFloat};
	while (i < 4)
	{
		if (FooPtr[i](num) == 0)
			break ;
		i++;
	}
	if (i == 4)
		return (1);
	std::string hay = "+inff-inffnanf";
	conv_to_char(num, hay);
	conv_to_int(num, hay);
	conv_to_float(num, hay);
	conv_to_double(num, hay);
	return (0);
}

int	ScalarConverter::CheckInt(std::string num)
{
	size_t	i;

	i = 0;
	while (num[i])
	{
		if (num[i] == '-' || num[i] == '+')
			i++;
		if (isdigit(num[i]))
			i++;
		else
			return (1);
	}
	return (0);
}

int ScalarConverter::CheckChar(std::string num)
{
	if (num.length() == 1)
	{
		if (!isprint(num[0]))
			return (1);
		return (0);
	}
	return (1);
}

int ScalarConverter::CheckFloat(std::string num)
{
	size_t c;
	size_t i;


	i = 0;
	c = 0;
	if (num == "-inff" || num == "+inff" || num == "nanf")
		return (0);
	while (i < num.length())
	{
		if (num[i] == '.' && isdigit(num[i+1]))
		{
			c = 1;
			i++;
		}
		else if (isdigit(num[i]) || (num[i] == 'f' && num[i+1] == '\0'))
			i++;
		else
			return (1);
	}
	if (c == 1)
		return (0);
	return (1);
}


int ScalarConverter::CheckDouble(std::string num)
{
	size_t i;
	size_t c;

	c = 0;
	i = 0;
	if (num == "-inf" || num == "+inf" || num == "nan")
		return (0);
	if (num[i] == '-' || num[i] == '+')
		i++;
	while (i < num.length())
	{
		if (num[i] == '.' && isdigit(num[i+1]))
		{
			c = 1;
			i++;
		}
		else if (isdigit(num[i]) || (num[i] == 'f' && num[i+1] == '\0'))
			i++;
		else
			return (1);
	}
	if (c == 1)
		return (0);
	return (1);
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */