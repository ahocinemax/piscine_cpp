#include <iostream>
#include "../includes/Scalar.Class.hpp"

int main (int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "usage: ./Converter [LITERAL VALUE]" << std::endl;
		return (0);
	}
	av++;
	std::string str = *av;
	char		*tmp = *av;
	try
	{
		if (str.size() != 1)
		{
			int	i = 0;
			if (*tmp == '-' || *tmp == '+')
				i++;
			while (tmp[i])
			{
				if (tmp[i] < '0' || tmp[i] > '9')
				{
					std::cerr << "not a digit" << std::endl;
					throw Scalar::InvalidInputException();
				}
				i++;
			}
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (0);
	}
	
	try
	{
		Scalar	mod(str);
		std::cout << mod << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}
	return (0);
}
