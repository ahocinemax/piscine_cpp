#include "PmergeMe.hpp"

void	PmergeMe::add(int val)
{
	_set.insert(val);
}

void	PmergeMe::sort()
{
	std::set<int>::const_iterator it;
	for (it = _set.begin(); it != _set.end(); ++it)
		++_map[*it];
}

void	PmergeMe::print() const
{
	std::map<int, int>::const_iterator it;
	for (it = _map.begin(); it != _map.end(); ++it)
	{
		for (int i = 0; i < it->second; ++i)
			std::cout << it->first << " ";
	}
	std::cout << std::endl;
}

bool	PmergeMe::parse(std::string str)
{
	std::stringstream ss(str); // Convertit la chaîne de caractères en un flux de lecture
	std::string token;

	// Utilise l'espace comme délimiteur
	while (std::getline(ss, token, ' '))
	{
		 // On ignore les espaces vides (ex: "  1  2 3" => "1" "2" "3")
		if (token == "")
			continue;
		// On vérifie que chaque caractère est un chiffre
		if (token.find_first_not_of("0123456789") != std::string::npos)
		{
			std::cout << "Error: invalid character in input" << std::endl;
			return (false);
		}
		int val = std::atoi(token.c_str());
		if (val < 0)
		{
			std::cout << "Error: negative numbers are not allowed" << std::endl;
			return (false);
		}
		add(val);
	}
	return (true);
}

std::set<int> &PmergeMe::getData()  { return _set; }