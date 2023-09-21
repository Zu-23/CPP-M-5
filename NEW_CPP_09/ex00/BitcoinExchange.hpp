#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include<map>

class Bitcoin
{
	private:
		std::map<std::string, float> map;
		void insert_map_data(std::string date, float val);
		void get_data(std::string file_name);
		int parse_date(std::string subline, int unsc, std::string line);
		double parse_value(std::string line);
		std::string trim(const std::string& str);
		std::string get_date(std::string &line);
		int check_month_day(std::string date);
		void calculate_data(std::string date, float value);
		void parse_row(std::string line);
	public:
		Bitcoin();
		Bitcoin(Bitcoin &obj);
		~Bitcoin();
Bitcoin&operator=(Bitcoin &obj);

		void parse_file(char *file_name);
};


#endif