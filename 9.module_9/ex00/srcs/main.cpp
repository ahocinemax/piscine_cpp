
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

	// for (std::size_t i = 0; i < ReqDb.getRequest().size(); i++)
	// {
	// 	for (std::size_t j = 0; j < ReqDb.getRequest()[i].size(); j++)
	// 	{
	// 		std::cout << ReqDb.getRequest()[i][j] << " ";
	// 	}
	// 	std::cout << std::endl;
	// }

	return (0);
}
