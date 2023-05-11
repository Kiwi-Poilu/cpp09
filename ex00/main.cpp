#include "BitcoinExchange.hpp"

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
		return (false);
	if (date.find_first_not_of("0123456789-") != std::string::npos)
		return (false);
	while (std::getline(tmp, str, '-'))
	{
		ymd[i] = atoi(str.c_str());
		if (ymd[i] == 0)
			return (false);
		i++;
	}
	if (checkDigits(ymd[0], ymd[1], ymd[2]) == false)
		return (false);
	return (true);
}

int formatRet(int code, std::string input)
{
	if (code == BAD_INPUT)
		std::cout << RED << "Error: bad input" << RESET << " => " << input << std::endl;
	if (code == NEG_VALUE)
		std::cout << RED << "Error: not a positive number." << RESET << std::endl;
	if (code == BIG_VALUE)
		std::cout << RED << "Error: too large a number." << RESET << std::endl;
	if (code == BAD_DATE)
		std::cout << RED << "Error: problem with the date." << RESET << std::endl;
	return (false);
}

int	checkLine(std::string line, std::map<std::string, float> values)
{
	size_t pos;
	std::string date;
	float value;
	std::string valueString;

	pos = line.find(" | ");
	if (pos == std::string::npos)
		return (formatRet(BAD_INPUT, line));
	valueString = line.substr(pos + 3);
	if (valueString.empty())
		return (formatRet(BAD_INPUT, line));
	date = line.substr(0, pos);
	std::istringstream checkValue(valueString);
	checkValue >> std::noskipws >> value;
	if (!checkValue.eof() || checkValue.fail())
		return (formatRet(BAD_INPUT, line));
	if (value > 1000)
		return (formatRet(BIG_VALUE, ""));
	if (value < 0)
		return (formatRet(NEG_VALUE, ""));
	if (!valiDate(date))
		return (formatRet(BAD_DATE, ""));
	std::map<std::string, float>::iterator it;
	it = values.find(date);
	if (it == values.end())
	{
		it = values.lower_bound(date);
		if (it != values.begin())
			it--;
		std::cout << YELLOW << date << " => " << value << " = " << value * it->second << RESET << std::endl;
	}
	else
		std::cout << GREEN << date << " => " << value << " = " << value * it->second << RESET << std::endl;
	return (true);
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
		return (false);
	}
	getline(csv, line);
	while (getline(csv, line))
	{
		std::stringstream tmp(line);
		getline(tmp, date, ',');
		tmp >> value;
		values.insert(std::make_pair(date, value));
	}
	return (true);
}

int	main(int ac, char **av)
{
	std::map<std::string, float> values;
	std::ifstream provided;
	std::string line;

	if (ac != 2)
	{
		std::cout << "Error: could not open file." << std::endl;
		return (0);
	}
	if (fillValues(values) == 0)
		return (0);
	provided.open(av[1]);
	if (!provided)
	{
		std::cout << "Error: could not open file." << std::endl;
		return (0);
	}
	getline(provided, line);
	if (line.compare("date | value") != 0)
	{
		std::cout << "Error: input file format is invalid" << std::endl;
	}
	while (getline(provided, line))
		checkLine(line, values);
	return (0);
}