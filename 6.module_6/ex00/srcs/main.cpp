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
