#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const char *request)
{
	_request = parseRequest(request);
	_database = parseDatabase("bitcoin.csv");
	if (_database.empty())
		throw OpenFileException();
	if (_database[0][0].compare("date") != 0 || _database[0][1].compare("exchange_rate") != 0)
		throw OpenFileException();
	if (_request[0][0].compare("date ") != 0 || _request[0][1].compare(" value") != 0)
		throw OpenFileException();
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
	std::map<std::string, std::string>::iterator dbIt= _database.begin();

	while (++reqIt != _request.end()) // Tant qu'il y a des requetes
	{
		if (!isValid(reqIt, dbIt + 1)) // Si la requete n'est pas valide, on ecrit l'erreur
			continue; // On passe a la requete suivante
		while (++dbIt != _database.end()) // Tant qu'il y a des valeurs dans la base de donnees
		{
			if ((*reqIt)[0] == (*dbIt)[0]) // Si la date de la requete est egale a la date de la base de donnees
			{
				{ // On affiche la valeur
					float value = atof((*dbIt)[1].c_str()) * atof((*reqIt)[1].c_str());
					std::cout << (*reqIt)[0] << " => " << (*reqIt)[1] << " = " << value << std::endl;
				}
			}
		}
		dbIt = _database.begin(); // On remet le pointeur de la base de donnees au debut
	}
}

std::pair<std::string, std::string> getNextLineAndSplitIntoTokens(std::istream& str, const char separator)
{
	// std::pair<std::string, std::string>	result;
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
	if (line.empty() || line[1].empty())
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
		vec.push_back(line);
	}
	return (vec);
}

std::map<std::string, std::string> parseDatabase(const char *argv)
{
	std::map<std::string, std::string>  vec;
	std::vector<std::string>                line;
	std::ifstream                           file(argv);
	if (!file.is_open())
		throw BitcoinExchange::OpenFileException();
	while (file.good())
	{
		// Read a line from File into a std::vector<std::string>
		line = getNextLineAndSplitIntoTokens(file, ',');
		// Add the above std::vector<std::string> to a std::map<std::string, std::string>
		vec.push_back(line);
	}
	return (vec);
}

bool isNumeric(std::string str)
{
	std::size_t	realNumberSize = 0;
	int			pointCounter = 0;

	// Compte le nombre de chiffres en sautant les 0
	while (str[realNumberSize] == '0')
		realNumberSize++;
	for (std::size_t i = 0 ; i < str.length() ; i++)
	{
		if (!isdigit(str[i]))
		{
			if (i == 0 && (str[i] == '+' || str[i] == '-'))
				continue;
			// Compte le nombre de points, ou quitte si ce n'en est pas un
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

bool	isValid(std::map<std::string, std::string>::iterator reqIt, std::map<std::string, std::string>::iterator dbIt)
{
	if (!isValidDate((*reqIt)[0]) || !isValidDate((*dbIt)[0]) || (*reqIt).size() != 2)
	{
		std::cerr << "Error: bad input => " << (*reqIt)[0] << std::endl;
		return (false);
	}
	if (!isNumeric((*reqIt)[1]))
	{
		std::cerr << "Error: bad input => " << (*reqIt)[0] << std::endl;
		return (false);
	}
	if (atoi((*reqIt)[1].c_str()) < 0)
	{
		std::cerr << "Error: Not a positive number." << std::endl;
		return (false);
	}
	if (atoi((*reqIt)[1].c_str()) > 1000)
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