#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <iostream>
#include<algorithm>
#include<vector>

class Error404NotFound: public std::exception
{
public:
	virtual const char* what() const throw()
	{
		return ("Error 404 Not Found");
	}
};

template<typename T>
void	easyfind(T& conta, int i)
{
	typename T::const_iterator it;
	it = std::find(conta.begin(), conta.end(), i);
	try
    {
		if (it == conta.end())
			throw (Error404NotFound());
	}
	catch (std::exception & exception)
    {
		std::cout << exception.what() << std::endl;
		return ;
	}
	std::cout  << "Element found: " << *it << std::endl;
}
#endif