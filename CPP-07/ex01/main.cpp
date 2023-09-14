#include "iter.hpp"

int main()
{
    int intArray[] = {1, 2, 3, 4, 5};
    char charArray[] = {'a', 'b', 'c', 'd', 'e'};
    iter(intArray, 5, printElement<int>);
    std::cout << std::endl;
    iter(charArray, 5, printElement<char>);
    std::cout << std::endl;

    return 0;
}