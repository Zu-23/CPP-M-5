#include "easyfind.hpp"

int main()
{
    std::vector<int> vec;
	for (int i = 0; i <= 100; i++)
		vec.push_back(i);
	easyfind(vec, 30);
	easyfind(vec, 69);

    return 0;
}
