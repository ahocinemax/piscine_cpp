
#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	std::vector<std::vector<std::string> >  bitcoinDb;
	BitcoinExchange  ReqDb(*(++argv));

	if (argc != 2)
	{
		std::cout << "Usage: ./btc <data.csv>" << std::endl;
		return (1);
	}

	// Parse bitcoin prices database to a vector list
	ReqDb.getValues();
	
	return (0);
}
