#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include<map>;

class Bitcoin
{
	private:
		std::map<int, float> map;
	public:
	Bitcoin();
	Bitcoin(const Bitcoin &obj);
	~Bitcoin();
	operator=(const Bitcoin &obj);
}