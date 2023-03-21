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
	std::string	token;
	std::string	delimiters(" \t\v\r");
	std::string	tokens("+-*/");
	std::string	numbers("0123456789");

	size_t		pos = 0;
	while ((pos = str.find_first_of(delimiters)) != std::string::npos)
		str.erase(pos, 1);
	while (!str.empty())
	{
		pos = str.find_first_of(tokens);
		if (pos != std::string::npos)
		{
			rpn.push_tokens(str.substr(pos, 1));
			str.erase(pos, 1);
		}
		pos = str.find_first_of(numbers);
		if (pos != std::string::npos)
		{
			rpn.push_digits(str.substr(pos, 1));
			str.erase(pos, 1);
		}
	}
	rpn.calculate();
	return 0;
}