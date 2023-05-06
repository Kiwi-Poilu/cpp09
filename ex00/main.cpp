#include <iostream>
#include <fstream>
#include "BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	// std::ifstream csv; //btc chart
	// std::ifstream provided; //dates we need to check
	if (ac!= 2)
	{
		std::cout << "Error: invalid number of arguments." << std::endl;
		return(0);
	}
	Exchange chart;
	// csv.open("data.csv");
	// provided.open(av[1]);
	// if (!provided)
	// {
	// 	std::cout << "Error: could not open " <<  av[1] << std::endl;
	// 	return(0);
	// }
}