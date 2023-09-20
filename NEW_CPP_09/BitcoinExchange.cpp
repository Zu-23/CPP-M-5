#include "BitcoinExchange.hpp"

Bitcoin::Bitcoin()
{
	parse_file("data.csv");
}

int Bitcoin::parse_file(char * file_name)
{
	std::ifstream   file;
    std::string     date;
	std::string     row;
    size_t          found;
    double          val;

    file.open(file_name);
	if (file.fail())
		throw(std::runtime_error("Error: could not open file"));
	while(std::getline(file, row))
	{
		if (row.find("date,exchange_rate") != std::string::npos)
            continue;
        found = row.find(',');
		if (found == std::string::npos)
			throw(std::runtime_error("The file has wrong data\n"));
		date = row.substr(0, found);
        try
        {
             val = std::stod(row.substr(found + 1));
        }
        catch(const std::exception& e)
        {
            std::cout << "Invalid file data"<< '\n';
        }
        this->inserto_map()
	}
    file.close();
}