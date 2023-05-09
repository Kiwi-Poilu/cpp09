#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
// #include <algorithm>

int	checkMonthes(int ymd[3])
{
	bool bi = false;
	int year = ymd[0];
	int month = ymd[1];
	int day = ymd[2];

	if (year % 4 == 0)
		bi = true;
	if (year < 2009)
		return (false);
	if (month > 12)
		return (false);
	if (month == 2)
	{
		if (bi == true && day > 29)
			return (false);
		else if (bi == false && day > 28)
			return (false);
		return (true);
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (day > 30)
			return (false);
		return (true);
	}
	else
		if (day > 31)
			return (false);
	return (true);
}


int	isValidDate(std::string date)
{
	int i = 0;
	std::stringstream tmp(date);
	std::string str;
	int ymd[3];
	while (std::getline(tmp, str, '-'))
	{
		ymd[i] = atoi(str.c_str());
		if (ymd[i] == 0)
			std::cout << "Invalid format for date" << std::endl;
		else
			// std::cout << "ymd[" << i << "] = " << ymd[i] << std::endl;
		i++;
	}
	if (checkMonthes(ymd) == 0)
		std::cout << "Invalid date" << std::endl;
	return (0);
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
		// std::remove(date.begin(), date.end(), ' ');
		std::cout << "date = " << date << "|" << "value =" << value << '|' << std::endl;
		values.insert({date, value});		
	}
	// for (std::map<std::string, float>::iterator it = values.begin(); it != values.end(); it++)
	// 	std::cout << it->first << " - " << it->second << std::endl;
	std::map<std::string, float>::iterator it ;
	getline(provided, line);
	while (getline(provided, line))
	{
		if (line.find(" | ") == std::string::npos)
			std::cout << "Error: bad input." << std::endl;
		// std::remove(line.begin(), line.end(), ' ');
		std::stringstream tmp(line);
		getline(tmp, date, '|');
		tmp >> value;
		if (value < 0)
			std::cout << "Error: not a positive number." << std::endl;
		if (value > 1000)
			std::cout << "Error: too large a number." << std::endl;
		// std::cout << "date[" << date << "]" << std::endl; 
		// std::cout << "date = " << date << "|" << "value =" << value << '|' << std::endl;
		isValidDate(date);
		it = values.find(date);
		std::cout << "Looking up date:"<< date << '.' << std::endl;
		if(it == values.end())
        {
			std::cout << "Key-value pair not present in map" << std::endl;
			std::cout << "Closest result: ";
			it = values.lower_bound(date);
			if (it != values.begin())
				it--;
			else
				std::cout << "Could not find previous closest key" << std::endl;
			std::cout << "Bitcoin was worth " << it->second << " the " << it->first << std::endl;
		}
		else
			std::cout << "Bitcoin was worth " << it->second << " the " << it->first << std::endl;
		std::cout << std::endl;
	}
}