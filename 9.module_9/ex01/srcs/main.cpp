#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./ex01 \"expression\"" << std::endl;
		return 1;
	}

	RPN		rpn;
	std::string	str(argv[1]);

	// Remove all spaces
	size_t		pos = 0;
	while ((pos = str.find_first_of(" \t\v\r")) != std::string::npos)
		str.erase(pos, 1);

	// Parse the string
	while (str.size())
	{
		if ((pos = str.find_last_of("+-*/")) != std::string::npos)
		{
			rpn.push_tokens(str.substr(pos, 1));
			str.erase(pos, 1);
		}
		else if ((pos = str.find_last_of("0123456789")) != std::string::npos)
		{
			rpn.push_digits(str.substr(pos, 1));
			str.erase(pos, 1);
		}
		else
		{
			std::cout << "Invalid expression" << std::endl;
			return 1;
		}
	}

	// Do the math
	rpn.calculate();

	return (0);
}