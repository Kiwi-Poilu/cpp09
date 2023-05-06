#include "BitcoinExchange.hpp"

Exchange::Exchange()
{
	std::ifstream csv;
	std::string line;
	std::string date;
	float value;

	csv.open("data.csv");
	if (!csv)	
		std::cout << "Error: could not open data.csv." << std::endl;
	while(getline(csv, line))
	{
		getline(line, date, ',');
		
		std::cout << date << std::endl;
		std::cout << line << std::endl;

	}
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