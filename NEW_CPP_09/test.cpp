#include<iostream>
#include<utility>
#include<map>
#include<string>
#include <fstream>
#include <string>


int main()
{
    std::ifstream   file;
    std::string     date;
	std::string     line;
    size_t          found;
    double          val;

    file.open("data.csv");
	while(std::getline(file, line))
	{
		if (line.find("date,exchange_rate") != std::string::npos)
            continue;
        found = line.find(',');
		if (found == std::string::npos)
			throw(std::runtime_error("The file has wrong data\n"));
		date = line.substr(0, found);
        try
        {
             val = std::stod(line.substr(found + 1));
        }
        catch(const std::exception& e)
        {
            std::cerr << "what the fuck is going on"<< '\n';
        }
        
       std::cout << "date = "  << date << " value =  " << val << std::endl;
	}
    file.close();
}
