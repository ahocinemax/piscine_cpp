
#include "BitcoinExchange.hpp"


std::vector<std::vector<std::string> > paseDatabase(const char *argv)
{
	std::vector<std::vector<std::string> >  vec;
	std::vector<std::string>                line;
	std::ifstream                           file(argv);
	if (!file.is_open())
		throw BitcoinExchange::OpenFileException();
	while (file.good())
	{
		// Read a line from File into a std::vector<std::string>
		line = getNextLineAndSplitIntoTokens(file);
		// Parse the data
		if (!parse(line))
			continue;
		// Add the above std::vector<std::string> to a std::vector<std::vector<std::string> >
		vec.push_back(line);
	}
	return vec;
}

int main(int argc, char **argv)
{
	std::vector<std::vector<std::string> >  bitcoinDb;
	BitcoinExchange  ReqDb(*(++argv));
	BitcoinExchange  ReqDb2();

	if (argc != 2)
	{
		std::cout << "Usage: ./btc <data.csv>" << std::endl;
		return (1);
	}

	// Parse bitcoin prices database to a vector list
	try
	{
		ReqDb.setDatabase(*argv);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	ReqDb.getValues();
	return (0);
}
