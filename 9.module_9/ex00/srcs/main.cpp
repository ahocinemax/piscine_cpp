
#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./btc <data.csv>" << std::endl;
		return (1);
	}
	try
	{
		BitcoinExchange  ReqDb(*(++argv));
		ReqDb.getValues();
	}
	catch(const BitcoinExchange::OpenFileException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(const BitcoinExchange::InvalidHeaderException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(const BitcoinExchange::WrongExtensionException &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
