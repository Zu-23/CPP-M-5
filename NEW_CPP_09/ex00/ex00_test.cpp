#include<iostream>
#include<utility>
#include<map>
#include<string>
#include <cstdlib>
#include <fstream>
#include <string>


// int parse_date(std::string subline, int unsc, std::string line)
// {
//     int flag = 0;
   

//     std::cout << subline << std::endl;
//     if (unsc == 0)
//     {
//         if (subline.size() != 4)
//             flag = 1;
//        for (size_t i = 0; i < subline.size(); i++)
//             if (!std::isdigit(subline[i]))
//                 flag = 1;
//     }
//     else
//     {
//         if (subline.size() != 2)
//             flag = 1;
//        try
//        {
//             double date = std::atoi(subline.c_str());
//             if (unsc == 1) //month
//             {
//                 if (date < 1 || date > 12)
//                     flag = 1;
//             }
//             else if (unsc == 2) //days
//             {
//                 if (date < 1 || date > 31)
//                     flag = 1;
//             }
//             for (size_t i = 0; i < subline.size(); i++)
//                 if (!std::isdigit(subline[i]))
//                     flag = 1; 
//        }
//        catch(const std::exception& e)
//        {
//             flag = 1;
//        }
//     }

//     if (flag)
//     {
//         std::cout << "Error: bad input => " << line << std::endl; 
//         return (1);
//     }
//     return (0);
// }

// int parse_value(std::string line)
// {
//     int flag = 0;
//     double val = 0;

//     for (size_t i = 0; i < line.size(); i++)
//     {
//         if ((!std::isdigit(line[i]) && line[i] != '.' )|| line.empty())
//         {
//             flag = 1;
//             break ;
//         }
//     }
//     try
//     {
//         val = std::strtod(line.c_str(), NULL);
//         if (val < 0)
//             flag = 2;
//         else if (val > 1000)
//             flag = 3;
//     }
//     catch(const std::exception& e)
//     {
//         flag = 1;
//     }
//     if (flag)
//     {
//         if (flag == 1 || flag == 3)
//             std::cout << "Error: too large a number" << std::endl;
//         else if (flag == 2)
//             std::cout << "Error: not a positive number" << std::endl;
//     }
//     return (flag);
// }


// std::string trim(const std::string& str)
// {
//     size_t start = str.find_first_not_of(" \t\n\r\f\v");
//     size_t end = str.find_last_not_of(" \t\n\r\f\v");

//     if (start == std::string::npos)
//         return "";
//     return str.substr(start, end - start + 1);
// }

// std::string get_date(std::string &line)
// {
//     size_t pos;
//     std::string apip;
//     pos = line.find('|');
//     if (pos == std::string::npos)
//         return ("");
//     apip = trim(line.substr(pos + 1));
//     line.erase(pos);
//     line = trim(line);
//     std::cout << "apip = " << apip << std::endl << "line = " << line << std::endl;
//     return (apip);
// }

// void inserto_pair(std::string date, float value)//problem: input date is uppered to the highest date
// {
//     std::map<std::string, float> map;
//     // map["2021-03-02"] = 6;
//     // map["2011-01-02"] = 3;
//     // map["2010-04-02"] = 7;
//     // map["2011-02-02"] = 5;
//     // map["2009-06-02"] = 8;
// 	std::pair<std::string, float> p(date, value);
// 	map.insert(p);
//     // std::map<std::string, float>::iterator it = map.lower_bound(p.first);
// 	std::map<std::string, float>::iterator it = map.begin();
// 	for(;it != map.end(); it++)
// 	{
// 		std::cout << it->first << " " << it->second << std::endl;
// 	}
// 	// if (it == map.end())
// 	// 	it--;
// 	// std::cout << "map date  = " << it->first << " map value = " << it->second 
// 	// << " date  =  " << date <<  " value = " << value << std::endl;
// }

int check_month_day()
{
    std::string date = "10212-04-04";
    int monthDays[] = {0,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	size_t pos = date.find('-') + 1;
    std::string stMonth = date.substr(pos, 2);
    std::string stDay = date.substr(pos + 3, 2);
    int month = std::atoi(stMonth.c_str());
    int day = std::atoi(stDay.c_str());
    std::cout << "month = " << stMonth << " day = " << stDay <<std::endl;
    if (monthDays[month] < day)
    {
        std::cout << "Error: bad input => " << date << std::endl;
        return (1);
    }
   return (0);
}

// void parse_row(std::string line)
// {
//     size_t pos;
//     size_t prev_pos;
//     int    unsc;
//     std::string apip;

//     prev_pos = 0;
//     unsc = 0;

//     apip = get_date(line);
//     if (apip.empty())
//     {
//         std::cout << "Error: bad input => " << line << std::endl;
//         return ;
//     }
//     for(size_t i = 0; i < 3; i++)
//     {
//         pos = line.find('-', prev_pos);
//         if (pos != std::string::npos)
//         {
//             if (parse_date(line.substr(prev_pos, pos - prev_pos), unsc, line))
//                 return ;
//             prev_pos = pos + 1;
//             unsc++;
//         }
//         else if (pos == std::string::npos)
//         {
//             if (unsc != 2)
//             {
//                 std::cout << "Error: bad input => " << line << std::endl;
//                 return ;
//             }
//             else
//                 if (parse_date(line.substr(prev_pos, pos - prev_pos), unsc, line))
//                     return ;
//         }
//     }
//     if (unsc != 2)
//     {
//         std::cout << "Error: bad input => " << line << std::endl;
//         return ;
//     }
//     //parse value
//     if (check_month_day(line) ||  parse_value(apip))
//         return ;
// }
int main()
{
    check_month_day();
}

