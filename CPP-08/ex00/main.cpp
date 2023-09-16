#include "easyfind.hpp"

int main()
{
	try
	{
		std::vector<int> vec;
		for (int i = 0; i <= 100; i++)
			vec.push_back(i);
		easyfind(vec, 30);
		easyfind(vec, 69);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

    return 0;
}
