
#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	std::map<std::string, std::string>  bitcoinDb;
	if (argc != 2)
	{
		std::cout << "Usage: ./btc <data.csv>" << std::endl;
		return (1);
	}
	BitcoinExchange  ReqDb(*(++argv));

	// for (std::size_t i = 0; i < ReqDb.getRequest().size(); i++)
	// {
	// 	for (std::size_t j = 0; j < ReqDb.getRequest()[i].size(); j++)
	// 	{
	// 		std::cout << ReqDb.getRequest()[i][j] << " ";
	// 	}
	// 	std::cout << std::endl;
	// }

	// Parse bitcoin prices database to a vector list
	ReqDb.getValues();
	
	return (0);
}
