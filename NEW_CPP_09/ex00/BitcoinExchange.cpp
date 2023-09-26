/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhaddoum <zhaddoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 23:51:33 by zhaddoum          #+#    #+#             */
/*   Updated: 2023/09/26 15:26:29 by zhaddoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

Bitcoin::Bitcoin()
{
	get_data("data.csv");
}

Bitcoin::Bitcoin(Bitcoin & obj)
{
	*this = obj;
}

Bitcoin& Bitcoin::operator=(Bitcoin & obj)
{
	if (this != &obj)
	{
		obj.map = this->map;
	}
	return (*this);
}

Bitcoin::~Bitcoin()
{}

void Bitcoin::insert_map_data(std::string date, float val)
{
	std::pair<std::string, float> p(date, val);
	this->map.insert(p);
}
void Bitcoin::get_data(std::string file_name)
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
             val = std::strtod(row.substr(found + 1).c_str(), NULL);
        }
        catch(const std::exception& e)
        {
            std::cout << "Invalid file data"<< '\n';
        }
        insert_map_data(date, val);
	}
    file.close();
}


int Bitcoin::parse_date(std::string subline, int unsc, std::string line)
{
	int flag;

	flag = 0;
	if (unsc == 0)
	{
	   for (size_t i = 0; i < subline.size(); i++)
			if (!std::isdigit(subline[i]))
				flag = 1;
  		int date = std::atoi(subline.c_str());
		if (date <= 0)
			flag = 1;
	}
	else
	{
	   try
	   {
			int date = std::atoi(subline.c_str());
			if (unsc == 1)
			{
				if (date <= 0 || date > 12)
					flag = 1;
			}
			else if (unsc == 2)
			{
				if (date <= 0 || date > 31)
					flag = 1;
			}
			for (size_t i = 0; i < subline.size(); i++)
				if (!std::isdigit(subline[i]))
					flag = 1; 
	   }
	   catch(const std::exception& e)
	   {
			flag = 1;
	   }
	}
	if (flag)
	{
		std::cout << "Error: bad input => " << line << std::endl; 
		return (1);
	}
	return (0);
}

double Bitcoin::parse_value(std::string line)
{
	int flag = 0;
	double val;

	try
	{
		for (size_t i = 0; i < line.size(); i++)
		{
			if ((!std::isdigit(line[i]) && line[i] != '.' ) || line.empty())
			{
				flag = 1;
				break ;
			}
		}
		if (flag == 0)
		{
			val = std::strtod(line.c_str(), NULL);
			if (val < 0)
				flag = 2;
			else if (val > 1000)
				flag = 3;
		}
	}
	catch(const std::exception& e)
	{
		flag = 1;
	}
	if (flag)
	{
		if (flag == 3)
			std::cout << "Error: too large a number" << std::endl;
		else if (flag == 1)
			std::cout << "Error: invalid number" << std::endl;
		else if (flag == 2)
			std::cout << "Error: not a positive number" << std::endl;
		return (-1);
	}
	return (val);
}


std::string Bitcoin::trim(const std::string& str)
{
	size_t start = str.find_first_not_of(" \t\n\r\f\v");
	size_t end = str.find_last_not_of(" \t\n\r\f\v");

	if (start == std::string::npos)
		return "";
	return str.substr(start, end - start + 1);
}

std::string Bitcoin::get_date(std::string &line)
{
	size_t pos;
	std::string apip;
	pos = line.find('|');
	if (pos == std::string::npos)
		return ("");
	apip = trim(line.substr(pos + 1));
	line.erase(pos);
	line = trim(line);
	return (apip);
}

int Bitcoin::check_month_day(std::string date)
{
	int monthDays[] = {0,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	size_t pos = date.find('-') + 1;
	int prpos = 0;
	std::string ar[3];
	for(int i = 0; i < 3; i++)
	{
		pos = date.find('-', prpos);
		ar[i] = date.substr(prpos, pos - prpos);
		prpos = pos + 1;
	}
	int year = std::atoi(ar[0].c_str());
    int month = std::atoi(ar[1].c_str());
    int day = std::atoi(ar[2].c_str());
	if (month == 2 && (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)))
        monthDays[month] = 29;

    if (day > monthDays[month])
    {
        std::cout << "Error: bad input => " << date << std::endl;
        return (1);
    }
   return (0);
}

void Bitcoin::parse_row(std::string line)
{
	size_t pos;
	size_t prev_pos;
	std::string apip;
	int     unsc;
	double     value;

	prev_pos = 0;
	unsc = 0;

	if (line == "date | value")
		return ;
	apip = get_date(line);
	if (apip.empty())
	{
		std::cout << "Error: bad input => " << line << std::endl;
		return ;
	}
	for(size_t i = 0; i < 3; i++)
	{
		pos = line.find('-', prev_pos);
		if (pos != std::string::npos)
		{
			if (parse_date(line.substr(prev_pos, pos - prev_pos), unsc, line))
				return ;
			prev_pos = pos + 1;
			unsc++;
		}
		else if (pos == std::string::npos)
		{
			if (unsc != 2)
			{
				std::cout << "Error: bad input1 => " << line << std::endl;
				return ;
			}
			else
				if (parse_date(line.substr(prev_pos, pos - prev_pos), unsc, line))
					return ;
		}
	}
	if (unsc != 2)
	{
		std::cout << "Error: bad input => " << line << std::endl;
		return ;
	}
	if (check_month_day(line) || (value = parse_value(apip)) == -1)
		return ;
    calculate_data(line, value);
}


void Bitcoin::calculate_data(std::string date, float value)
{
	std::pair<std::string, float> p(date, value);
    std::map<std::string, float>::iterator it = this->map.lower_bound(p.first);
	if (it == this->map.end())
		it--;
	std::cout << date << " => " << value << " = " << it->second * value << std::endl;
}

void    Bitcoin::parse_file(char *file_name)
{
	std::ifstream   file;
	std::string     date;
	std::string     row;

	file.open(file_name);
	if (file.fail())
		throw(std::runtime_error("Error: could not open file"));
	else if (file.peek() == std::ifstream::traits_type::eof())
	{
		file.close();
		throw(std::runtime_error("Error: empty file"));
	}
	while (std::getline(file, row))
	{
		if (row.empty())
			continue;
		parse_row(row);
	}
	file.close();
}



