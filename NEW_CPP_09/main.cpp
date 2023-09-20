#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>

int main(int ac, char **av)
{
    Bitcoin btc;
    if (ac != 2)
    {
        std::cout << "Error: could not open file." << std::endl;
        return (1);
    }
    else
    {
        btc.prase_file(file);
    }
    file.close();
}