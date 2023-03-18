#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const char *request)
{
	_request = parseDatabase(request);
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
	std::vector<std::vector<std::string> >::iterator it = _request.begin();
	std::vector<std::vector<std::string> >::iterator it2= _database.begin();

	while (it != _request.end())
	{
		while (it2 != _database.end())
		{
			if ((*it)[0] == (*it2)[0])
			{
				if (atof((*it)[1].c_str()) > INT_MAX)
					std::cerr << "Error: too large a number." << std::endl;
				else if (atof((*it)[1].c_str()) < 0)
					std::cerr << "Error: Not a positive number." << std::endl;
				else if (!isNumeric((*it)[1]) || !(*it)[1].length())
					std::cerr << "Error: bad input => " << (*it)[0] << std::endl; // 
				else
				{
					float value = atof((*it2)[1].c_str()) * atof((*it)[1].c_str());
					std::cout << (*it)[0] << " " << (*it)[1] << " " << value << std::endl;
				}
			}
			it2++;
		}
		it2 = _database.begin();
		it++;
	}
}

std::vector<std::string> getNextLineAndSplitIntoTokens(std::istream& str)
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

bool parse(std::vector<std::string> &line)
{
	if (line.size() != 2)
		return (false);
	if (line[0].empty() || line[1].empty())
		return (false);
	return (true);
}

std::vector<std::vector<std::string> > parseDatabase(char *argv)
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
		// Add the above std::vector<std::string> to a std::vector<std::vector<std::string> >
		vec.push_back(line);
	}
	return (vec);
}

std::vector<std::vector<std::string> > parseDatabase(const char *argv)
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
		// Add the above std::vector<std::string> to a std::vector<std::vector<std::string> >
		vec.push_back(line);
	}
	return (vec);
}

bool isNumeric(std::string str)
{
	int	point = 0;

	for (std::size_t i = 0; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
		{
			if (str[i] != '.')
				return (false);
			else
				point++;
		}
	}
	return (point == 0 || point == 1);
}

bool isValidDate(std::string dateStr)
{
    struct tm tm;
    return !(strptime(dateStr.c_str(), "%Y-%m-%d", &tm) == NULL); // Convertir la chaîne en structure tm
}
