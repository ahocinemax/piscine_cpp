#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void)
{
}

PmergeMe::~PmergeMe(void)
{
}

void	PmergeMe::print() const
{
	std::vector<int>::const_iterator it;
	std::cout << "After : ";
	for (it = _vector.begin(); it != _vector.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void	PmergeMe::sort_containers()
{
	clock_t     start, end;

	// Sorting the list container
	{
		srand(time(NULL));
		start = clock();

		_list = merge_sort(_list);

		end = clock();
		_elapsedList = ((double) (end - start)) / CLOCKS_PER_SEC;
	}
	// Sorting the vector container
	{
		srand(time(NULL));
		start = clock();

		_vector = merge_sort(_vector);

		end = clock();
		_elapsedVector = ((double) (end - start)) / CLOCKS_PER_SEC;
	}
}

bool	PmergeMe::parse(std::string str)
{
	std::stringstream ss(str); // Convertit la chaîne de caractères en un flux de lecture
	std::string token;

	// Utilise l'espace comme délimiteur
	while (std::getline(ss, token, ' '))
	{
		// On ignore les espaces (ex: "  1  2 3" => "1" "2" "3")
		if (token == "" || token == " ")
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
		getList().push_back(val);
		getVector().push_back(val);
	}
	return (true);
}

bool	PmergeMe::parseList(int argc, char **argv)
{
	for (int i = 0; i < argc - 1; ++i)
	{
		int val = std::atoi(argv[i]);
		if (val < 0)
		{
			std::cout << "Error: negative numbers are not allowed" << std::endl;
			return (false);
		}
		else if (val == 0 && argv[i][0] != '0')
		{
			std::cout << "Error: invalid character in input" << std::endl;
			return (false);
		}
		getList().push_back(val);
		getVector().push_back(val);
		std::cout << val << " ";
	}
	std::cout << std::endl;
	return (true);
}

std::vector<int> &PmergeMe::getVector() { return _vector; }

std::list<int>	&PmergeMe::getList() { return _list; }

double	PmergeMe::getElapsedVector() const { return _elapsedVector; }

double	PmergeMe::getElapsedList() const { return _elapsedList; }

std::list<int> PmergeMe::parse_input(const std::string& input)
{
	std::list<int>	nums;
	std::stringstream	ss(input);
	int					num;

	while (ss >> num)
		nums.push_back(num);
	return (nums);
}
