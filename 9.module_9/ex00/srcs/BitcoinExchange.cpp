#include "BitcoinExchange.hpp"

std::vector<std::vector<std::string> > parseDatabase(const char *argv);
std::vector<std::vector<std::string> > parseDatabase(char *argv);

BitcoinExchange::BitcoinExchange(const char *request)
{
	_request = parseDatabase(request);
	_database = parseDatabase("bitcoin.csv");
}

BitcoinExchange::BitcoinExchange()
{
	_database = parseDatabase("bitcoin.csv");
}

BitcoinExchange::~BitcoinExchange() 
{
}

void BitcoinExchange::setDatabase(const char *src)
{
	_request = parseDatabase(src);
}

void BitcoinExchange::setDatabase(char *src)
{
	_request = parseDatabase(src);
}

std::vector<std::vector<std::string> > BitcoinExchange::getDatabase(void)
{
	return (_database);
}

void BitcoinExchange::getValues(void)
{
	std::vector<std::vector<std::string> >::iterator it;
	std::vector<std::string>::iterator it2;

	for (it = _request.begin(); it != _request.end(); it++)
	{
		for (it2 = it->begin(); it2 != it->end(); it2++)
		{
			std::cout << *it2 << std::endl;
		}
	}
}

std::vector<std::vector<std::string> > BitcoinExchange::_paseDatabase(char *argv)
{
	std::vector<std::vector<std::string> >  vec;
	std::vector<std::string>                line;
	std::ifstream                           file(argv);
	if (!file.is_open())
		throw BitcoinExchange::OpenFileException();
	while (file.good())
	{
		// Read a line from File into a std::vector<std::string>
		line = this->_getNextLineAndSplitIntoTokens(file);
		// Parse the data
		if (!BitcoinExchange::_parse(line))
			continue;
		// Add the above std::vector<std::string> to a std::vector<std::vector<std::string> >
		vec.push_back(line);
	}
	return vec;
}

std::vector<std::string> BitcoinExchange::_getNextLineAndSplitIntoTokens(std::istream& str)
{
	std::vector<std::string>   result;
	std::string                line;
	std::getline(str,line);

	std::stringstream          lineStream(line);
	std::string                cell;

	while(std::getline(lineStream,cell, ','))
	{
		result.push_back(cell);
	}

	// This checks for a trailing comma with no data after it.
	if (!lineStream && cell.empty())
	{
		// If there was a trailing comma then add an empty element.
		result.push_back("");
	}
	return (result);
}

bool BitcoinExchange::_parse(std::vector<std::string> &line)
{
	if (line.size() != 2)
		return (false);
	if (line[0].empty() || line[1].empty())
		return (false);
	return (true);
}
