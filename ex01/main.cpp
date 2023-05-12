#include "RPN.hpp"

void	performRPN(char *str)
{
	int i = 0;
	int a, b, tmp;
	std::stack<int> rpn;

	while (str[i] != '\0')
	{
		if (isdigit(str[i]))
			rpn.push(atoi(str + i));
		else if (isOperator(str[i]))
		{
			if (rpn.size() < 2)
			{
				std::cout << "Error: not enough operands to apply an operator" << std::endl;
				return ;
			}
			a = rpn.top();
			rpn.pop();
			b = rpn.top();
			rpn.pop();
			tmp = calculate(str[i], a, b);
			rpn.push(tmp);
		}
		else
		{
			std::cout << "Error: invalid token in the expression" << std::endl;
			return ;
		}
		i++;
		if (str[i])
		{
			if (str[i] != ' ')
			{
				std::cout << "Error: invalid token in the expression" << std::endl;
				return ;
			}
			i++;
			if (!str[i])
			{
				std::cout << "Error: invalid token in the expression" << std::endl;
				return ;
			}
		}
	}
	if (rpn.size() == 1)
		std::cout << rpn.top() << std::endl;
	else
		std::cout << "Error: not a valid rpn expression" << std::endl;
	return ;
}

int	main(int ac, char **av)
{
	// int a, b;
	// int tmp;
	// // std::stack<int> rpn;
	// // std::string str;
	if (ac != 2)
	{
		std::cout << "Error: invalid number of arguments" << std::endl;
		return (0);
	}
	// int i = 0;	
	// str = av[1];
	// while (str[i])
	// {
		// if (isdigit(str[i]))
			// rpn.push(atoi(str.c_str() + i));
		// else if (isOperator(str[i]))
		// {
			// if (rpn.size() < 2)
			// {
				// std::cout << "Error: not enough operands to apply an operator" << std::endl;
				// return (0);
			// }
			// a = rpn.top();
			// rpn.pop();
			// b = rpn.top();
			// rpn.pop();
			// tmp = calculate(str[i], a, b);
			// rpn.push(tmp);
		// }
		// else
		// {
			// std::cout << "Error: invalid token in the expression" << std::endl;
			// return (0);
		// }
		// i++;
		// if (str[i])
		// {
			// if (str[i] == ' ')
				// i++;
			// else
			// {
				// std::cout << "Error: invalid token in the expression" << std::endl;
				// return (0);
			// }
		// }
// 
	// }
	// if (rpn.size() == 1)
		// std::cout << rpn.top() << std::endl;
	// else
		// std::cout << "Error: not a valid rpn expression" << std::endl;
	performRPN(av[1]);
	return (0);
}