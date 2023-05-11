#include <iostream>
#include <string>
#include <sstream>
#include <vector>

int	main(int ac, char **av)
{
	int i = 1;
	int tmp;
	std::vector<int> test; 
	if (ac < 2)
	{
		std::cout << "Error: not enough arguments" << std::endl;
		return (0);
	}
	while (i < ac)
	{
		std::istringstream checkInt(av[i]);
		checkInt >> tmp;
		if (checkInt.fail() || !checkInt.eof() || tmp < 0)
		{
			std::cout << "Error: not a valid list of integers" << std::endl;
			return (0);
		}
		std::cout << "[" << i << "]" << tmp << "," << std::endl;
		i++;
	}
}