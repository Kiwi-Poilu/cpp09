#include "BitcoinExchange.hpp"
#include <string>

int main(int ac, char **av)
{
	std::ifstream input;
	std::string line;
	if (ac != 2)
	{
		std::cout << "Error: wrong number of arguments" << std::endl;
		return (0);
	}
	input.open(av[1]);
	if (!input)
	{
		std::cout << "Error: could not open provided file" << std::endl;
		return (0);
	}
	getline(input, line);
	while (getline(input, line))
	{
		if (line.find(" | ") == std::string::npos)
			std::cout << "Error: bad input." << std::endl;
		std::remove(line.begin(), line.end(), ' ');
		
	}
}