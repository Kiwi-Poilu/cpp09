#include "BitcoinExchange.hpp"

Exchange::Exchange()
{
	std::ifstream csv;
	std::string line;
	std::string date;
	float value;

	csv.open("data.csv");
	// if (!csv)
	// 	throw 0;
	getline(csv, line);
	while (getline(csv, line))
	{
		std::stringstream tmp(line);
		getline(tmp, date, ',');
		tmp >> value;
		values.insert({date, value});		
	}
	for (std::map<std::string, float>::iterator it = values.begin(); it != values.end(); it++)
		std::cout << '|' << it->first << "->" << it->second << '|' << std::endl;
}

Exchange::Exchange( const Exchange & src )
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Exchange::~Exchange()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Exchange &				Exchange::operator=( Exchange const & rhs )
{
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}