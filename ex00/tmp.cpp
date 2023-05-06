#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>

int	isValidDate(std::string date)
{
	
}

int main(int ac, char **av)
{
	std::map<std::string, float> values;
	std::ifstream csv;		// btc chart
	std::ifstream provided; // dat
	std::string date;
	std::string line;
	float value;
	if (ac!= 2)
	{
		std::cout << "Error: invalid number of arguments." << std::endl;
		return(0);
	}
	csv.open("data.csv");
	if (!csv)
	{
		std::cout << "Could not open database" << std::endl;
		return (0);
	}
	provided.open(av[1]);
	if (!provided)
	{
		std::cout << "Error: could not open provided file" << std::endl;
		return(0);
	}
	getline(csv, line);
	while (getline(csv, line))
	{
		std::stringstream tmp(line);
		getline(tmp, date, ',');
		tmp >> value;
		values.insert({date, value});		
	}
	// for (std::map<std::string, float>::iterator it = values.begin(); it != values.end(); it++)
	// 	std::cout << it->first << " - " << it->second << std::endl;
	getline(provided, line);
	while (getline(provided, line))
	{
		std::stringstream tmp(line);
		getline(tmp, date, '|');
		tmp >> value;
	}
}