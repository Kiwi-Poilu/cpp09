#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <cstdlib>

int	checkDigits(int year, int month, int day)
{
	bool bi = false;

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

int	valiDate(std::string date)
{
	int ymd[3];
	int i = 0;
	std::istringstream tmp(date);
	std::string str;

	if (date.size() != 10)
	{
		std::cout << "Error: bad date format" << std::endl;
		return (false);
	}
	if (date.find_first_not_of("0123456789-") != std::string::npos)
	{
		std::cout << "Error: bad date format" << std::endl;
		return (false);
	}
	while (std::getline(tmp, str, '-'))
	{
		ymd[i] = atoi(str.c_str());
		if (ymd[i] == 0)
		{
			std::cout << "Error: ymd can't be 0." << std::endl;
			return (false);
		}
		i++;
	}
	if (checkDigits(ymd[0], ymd[1], ymd[2]) == false)
		return (false);
	return (true);
}

int	checkLine(std::string line, std::map<std::string, float> values)
{
	size_t pos;
	std::string date;
	float value;
	std::string valueString;

	pos = line.find(" | ");
	if (pos == std::string::npos)
	{
		std::cout << "Error: bad input => " << line << std::endl;
		return (false);
	}
	valueString = line.substr(pos + 3);
	if (valueString.empty())
	{
		std::cout << "Error: bad input." << std::endl;
		return (false);
	}
	date = line.substr(0, pos);
	// std::cout << date << "[" << valueString << "]\n";
	std::istringstream checkValue(valueString);
	checkValue >> std::noskipws >> value;
	if (!checkValue.eof() || checkValue.fail())
	{
		std::cout << "Error: bad value" << std::endl;
		return (false);
	}
	if (value > 1000)
	{
		std::cout << "Error: too large a number." << std::endl;
		return (false);
	}
	if (value < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return (false);
	}
	if (!valiDate(date))
		return (false);
	std::map<std::string, float>::iterator it;
	it = values.find(date);
	if (it == values.end())
	{
		it = values.lower_bound(date);
		if (it != values.begin())
			it--;
	}
	std::cout << date << " => " << value << " = " << value * it->second << std::endl;
	return (true);
}

int	outputResults(char *input, std::map<std::string, float> values)
{
	std::ifstream provided;
	std::string line;
	provided.open(input);
	if (!provided)
	{
		std::cout << "Error: could not open provided file." << std::endl;
		return (1);
	}
	getline(provided, line);
	while (getline(provided, line))
		checkLine(line, values);
	return (0);
}

int	fillValues(std::map<std::string, float> &values)
{
	std::ifstream csv;
	std::string line;
	std::string date;
	float value;
	
	csv.open("data.csv");
	if (!csv)
	{
		std::cout << "Error: could not open database." << std::endl;
		return (1);
	}
	getline(csv, line);
	while (getline(csv, line))
	{
		std::stringstream tmp(line);
		getline(tmp, date, ',');
		tmp >> value;
		values.insert(std::make_pair(date, value));
	}
	return (0);
}

int	main(int ac, char **av)
{
	std::map<std::string, float> values;

	if (ac != 2)
	{
		std::cout << "Error: invalid number of arguments." << std::endl;
		return (0);
	}
	if (fillValues(values))
		return (0);
	// for (std::map<std::string, float>::iterator it = values.begin(); it != values.end(); it++)
		// std::cout << it->first << " - " << it->second << std::endl;
	outputResults(av[1], values);
}