#include <iostream>
#include <sstream>
#include <string>

int main(int ac, char **av)
{
    std::string a = "23-55-3-0     ";
    std::istringstream ss(a);

    int v;
    while (ss >> v)
    {
        std::cout << v << " ";
    }
}
