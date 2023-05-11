#include "RPN.hpp"

int	isOperator(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return (1);
	return (0);
}

int calculate(char op, int a, int b)
{
	if (op == '+')
		return (b + a);
	if (op == '-')
		return (b - a);
	if (op == '/')
		return (b / a);
	if (op == '*')
		return (b * a);
	return (0);
}