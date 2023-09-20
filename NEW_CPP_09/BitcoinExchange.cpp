#include "BitcoinExchange.hpp"

Bitcoin::Bitcoin()
{
	get_data("data.csv");
}

void Bitcoin::get_data(char * file_name)
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
        this->inserto_map();
	}
    file.close();
}

void::Bitcoin::parse_date(std::string line, int unsc)
{
    std::cout << line << std::endl;
    if (unsc == 0)
    {
        if (line.size() != 4)
            throw(std::runtime_error("Invalid date | value\n"));
        
    }
}

void Bitcoin::parse_row(std::string line)
{
    //parse date
    size_t pos;
    size_t prev_pos;
    int    unsc;

    prev_pos = 0;
    unsc = 0;
    for(size_t i = 0; i < 3; i++)
    {
        pos = line.find('-', prev_pos);
        if (pos != std::string::npos)
        {
            parse_date(line.substr(prev_pos, pos - prev_pos), unsc);
            prev_pos = pos + 1;
            unsc++;
        }
        else if (pos == std::string::npos)
        {
            if (unsc != 2)
                std::cout << "error" << std::endl;
            else
                parse_date(line.substr(prev_pos, pos - prev_pos));
        }
    }
    if (unsc != 2)
        throw(std::runtime_error("Invalid date | value\n"));
    //parse value
    {

    }
}

void    Bitcoin::parse_file(char *file_name)
{
    std::ifstream   file;
    std::string     date;
	std::string     row;
    size_t          found;
    double          val;

    file.open(file_name);
    if (file.fail())
        throw(std::runtime_error("Error: could not open file"));
    while (std::getline(file, row))
    {
        parse_row(row);
    }
}

