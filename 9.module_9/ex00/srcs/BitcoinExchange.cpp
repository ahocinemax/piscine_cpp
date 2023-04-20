#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const char *request)
{
	_request = parseRequest(request);
	_database = parseDatabase("bitcoin.csv");
	std::string	req = request;

	// Check for the extension of the file
	if (req.size() <= 4 || req.substr(req.size() - 4, 4).compare(".csv") != 0)
		throw WrongExtensionException();
	if (_database.empty())
		throw OpenFileException();
	// Check for the header of files
	if (_database.find("date")->second.compare("exchange_rate") != 0)
		throw OpenFileException();
	if (_request.find("date ")->second.compare(" value") != 0)
		throw InvalidHeaderException();
	_request.erase("date ");
	_database.erase("date");
}

BitcoinExchange::~BitcoinExchange() 
{
}

void BitcoinExchange::setDatabase(const char *src)
{
	_request = parseDatabase(src);
}

std::map<std::string, std::string> BitcoinExchange::getDatabase(void)
{
	return (_database);
}

std::map<std::string, std::string> BitcoinExchange::getRequest(void)
{
	return (_request);
}

void BitcoinExchange::getValues(void)
{
	std::map<std::string, std::string>::iterator reqIt = _request.begin();
	std::map<std::string, std::string>::iterator dbIt;

	for ( ; reqIt != _request.end() ; reqIt++) // Tant qu'il y a des requetes
	{
		dbIt = _database.lower_bound((*reqIt).first); // On cherche la date de la requete dans la base de donnees
		if (!isValid(reqIt, dbIt)) // Si la requete n'est pas valide, on ecrit l'erreur
			continue; // On passe a la requete suivante

		std::cout << "key: " << (*dbIt).first << "\nvalue: " << (*dbIt).second << std::endl;
		float value = atof((*dbIt).second.c_str()) * atof((*reqIt).second.c_str());
		std::cout << (*dbIt).first << " => " << (*reqIt).second << " = " << value << std::endl;
	}
}

std::pair<std::string, std::string> getNextLineAndSplitIntoTokens(std::istream& str, const char separator)
{
	std::string	line;
	std::getline(str,line);

	std::stringstream	lineStream(line);
	std::string			key;
	std::string			val;

	std::getline(lineStream, key, separator);
	std::getline(lineStream, val);

	std::pair<std::string, std::string>	result(key, val);

	return (result);
}

bool parse(std::map<std::string, std::string> &line)
{
	if (line.size() != 2)
		return (false);
	if (line.empty() || (line.begin())->second.empty())
		return (false);
	return (true);
}

std::map<std::string, std::string> parseRequest(const char *argv)
{
	std::pair<std::string, std::string>	line;
	std::map<std::string, std::string>	vec;
	std::ifstream						file(argv);

	if (!file.is_open())
		throw BitcoinExchange::OpenFileException();
	while (file.good())
	{
		// Read a line from File into a std::vector<std::string>
		line = getNextLineAndSplitIntoTokens(file, '|');
		// Add the above std::vector<std::string> to a std::map<std::string, std::string>
		vec.insert(line);
	}
	return (vec);
}

std::map<std::string, std::string> parseDatabase(const char *argv)
{
	std::map<std::string, std::string>	vec;
	std::pair<std::string, std::string>	line;
	std::ifstream						file(argv);
	if (!file.is_open())
		throw BitcoinExchange::OpenFileException();
	while (file.good())
	{
		// Read a line from File into a std::vector<std::string>
		line = getNextLineAndSplitIntoTokens(file, ',');
		// Add the above std::vector<std::string> to a std::map<std::string, std::string>
		if (line.first.c_str())
			vec.insert(line);
	}
	return (vec);
}

bool isNumeric(std::string str)
{
	std::size_t	realNumberLen = 0;
	int			pointCounter = 0;

	// Count real len of number
	while (str[realNumberLen] == '0')
		realNumberLen++;
	for (std::size_t i = 0 ; i < str.length() ; i++)
	{
		if (!isdigit(str[i]))
		{
			if (i == 0 && (str[i] == '+' || str[i] == '-'))
				continue ;
			// Count points and leave if actual character it not
			if (str[i] != '.')
				return (false);
			else
				pointCounter++;
		}
	}
	return (pointCounter == 0 || pointCounter == 1);
}

bool isValidDate(std::string dateStr)
{
	struct tm tm;
	return (strptime(dateStr.c_str(), "%Y-%m-%d", &tm) != NULL); // Convertir la chaîne en structure tm
}

bool	BitcoinExchange::isValid(std::map<std::string, std::string>::iterator reqIt, std::map<std::string, std::string>::iterator dbIt)
{
	if (reqIt == _request.end() || dbIt == _database.end())
		return (false);
	if (!isValidDate((*reqIt).first) || !isValidDate((*dbIt).first) || (*reqIt).second.empty())
	{
		std::cerr << "Error: bad input => " << (*reqIt).first << std::endl;
		return (false);
	}
	if (!isNumeric((*reqIt).second))
	{
		std::cerr << "Error: bad input => " << (*reqIt).first << std::endl;
		return (false);
	}
	if (atoi((*reqIt).second.c_str()) < 0)
	{
		std::cerr << "Error: Not a positive number." << std::endl;
		return (false);
	}
	if (atoi((*reqIt).second.c_str()) > 1000)
	{
		std::cerr << "Error: too large a number." << std::endl;
		return (false);
	}
	return (true);
}

const char	*BitcoinExchange::OpenFileException::what(void) const throw()
{
	return "Error: Could not open file.";
}

const char	*BitcoinExchange::InvalidHeaderException::what(void) const throw()
{
	return "Error: Invalid header \"date | value\"";
}

const char *BitcoinExchange::WrongExtensionException::what(void) const throw()
{
	return "Error: File must have \"NAME.csv\" extension";
}