#include<iostream>
#include<utility>
#include<map>
#include<string>
#include <cstdlib>
#include <fstream>
#include <string>


int parse_date(std::string subline, int unsc, std::string line)
{
    int flag = 0;
   

    std::cout << subline << std::endl;
    if (unsc == 0)
    {
        if (subline.size() != 4)
            flag = 1;
       for (size_t i = 0; i < subline.size(); i++)
            if (!std::isdigit(subline[i]))
                flag = 1;
    }
    else
    {
        if (subline.size() != 2)
            flag = 1;
       try
       {
            double date = std::atoi(subline.c_str());
            if (unsc == 1) //month
            {
                if (date < 1 || date > 12)
                    flag = 1;
            }
            else if (unsc == 2) //days
            {
                if (date < 1 || date > 31)
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

int parse_value(std::string line)
{
    int flag = 0;
    double val = 0;

    for (size_t i = 0; i < line.size(); i++)
    {
        if ((!std::isdigit(line[i]) && line[i] != '.' )|| line.empty())
        {
            flag = 1;
            break ;
        }
    }
    try
    {
        val = std::strtod(line.c_str(), NULL);
        if (val < 0)
            flag = 2;
        else if (val > 1000)
            flag = 3;
    }
    catch(const std::exception& e)
    {
        flag = 1;
    }
    if (flag)
    {
        if (flag == 1 || flag == 3)
            std::cout << "Error: too large a number" << std::endl;
        else if (flag == 2)
            std::cout << "Error: not a positive number" << std::endl;
    }
    return (flag);
}


std::string trim(const std::string& str)
{
    size_t start = str.find_first_not_of(" \t\n\r\f\v");
    size_t end = str.find_last_not_of(" \t\n\r\f\v");

    if (start == std::string::npos)
        return "";
    return str.substr(start, end - start + 1);
}

std::string get_date(std::string &line)
{
    size_t pos;
    std::string apip;
    pos = line.find('|');
    if (pos == std::string::npos)
        return ("");
    apip = trim(line.substr(pos + 1));
    line.erase(pos);
    line = trim(line);
    std::cout << "apip = " << apip << std::endl << "line = " << line << std::endl;
    return (apip);
}

void inserto_pair(std::string date, float value)
{
    std::map<std::string, float> map;
    map["2011-01-02"] = 94;
    map.insert(std::pair<std::string, float>("33", 3));
    std::cout << map["2011-01-02"] << std::endl;
	std::pair<std::string, float> p(date, value);
}

int check_month_day(std::string date)
{
    int monthDays[] = {0,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    std::string stMonth = date.substr(5,2);
    std::string stDay = date.substr(8,2);
    int month = std::atoi(stMonth.c_str());
    int day = std::atoi(stDay.c_str());
    std::cout << "day = " << day << " month " << month << std::endl;
    if (monthDays[month] < day)
    {
        std::cout << "Error: bad input => " << date << std::endl;
        return (1);
    }
   return (0);
}

void parse_row(std::string line)
{
    size_t pos;
    size_t prev_pos;
    int    unsc;
    std::string apip;

    prev_pos = 0;
    unsc = 0;

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
                std::cout << "Error: bad input => " << line << std::endl;
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
    //parse value
    if (check_month_day(line) ||  parse_value(apip))
        return ;
}
int main()
{
   // parse_row("2010-01-01 | 34");
   std::string line ="2011-01-02";

   check_month_day(line);
//   get_date(line);
 // parse_row(line);
 //inserto_pair("",0);
}

