#include "PmergeMe.hpp"

// Public

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

	// std::list<int>::const_iterator it2;
	// std::cout << "A.lst : ";
	// for (it2 = _list.begin(); it2 != _list.end(); ++it2)
	// 	std::cout << *it2 << " ";
	// std::cout << std::endl;
}

void	PmergeMe::sort_containers()
{
	clock_t     start, end;

	// Sorting the list container
	{
		srand(time(NULL));
		start = clock();
		_list = mergeSort(_list);
		end = clock();
		_timeList = ((double) (end - start)) / CLOCKS_PER_SEC;
	}
	// Sorting the vector container
	{
		srand(time(NULL));
		start = clock();
		mergeSort(0, _vector.size() - 1);
		end = clock();
		_timeVector = ((double) (end - start)) / CLOCKS_PER_SEC;
	}
}

void	PmergeMe::parse(std::string str)
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
		if (token[0] == '-')
			throw NegativeNumberException();
		if (token.find_first_not_of("0123456789") != std::string::npos)
			throw InvalidInputException();

		int val = std::atoi(token.c_str());
		if (val <= 0 && token[0] != '0')
			throw OverflowException();
		getList().push_back(val);
		getVector().push_back(val);
	}
}

void	PmergeMe::parseList(int argc, char **argv)
{
	for (int i = 0; i < argc - 1; ++i)
	{
		std::string	str(argv[i]);
		if (str[0] == '-')
			throw NegativeNumberException();
		else if (str.find_first_not_of("0123456789") != std::string::npos)
			throw InvalidInputException();

		int val = std::atoi(argv[i]);
		if (val <= 0 && str[0] != '0')
			throw OverflowException();
		getList().push_back(val);
		getVector().push_back(val);
	}
}

std::vector<int>	&PmergeMe::getVector() { return _vector; }

std::list<int>	&PmergeMe::getList() { return _list; }

double	PmergeMe::getTimeVector() const { return _timeVector; }

double	PmergeMe::getTimeList() const { return _timeList; }

// Private

// Ajoute les paramètres dans la liste
std::list<int>	PmergeMe::parse_input(const std::string& input)
{
	std::list<int>	nums;
	std::stringstream	ss(input);
	int					num;

	while (ss >> num)
		nums.push_back(num);
	return (nums);
}

std::list<int> PmergeMe::merge(std::list<int>& left, std::list<int>& right)
{
	std::list<int> result;
	while (left.size() > 0 || right.size() > 0)
	{
		if (left.size() > 0 && right.size() > 0)
		{
			if (left.front() <= right.front())
			{
				result.push_back(left.front());
				left.pop_front();
			}
			else
			{
				result.push_back(right.front());
				right.pop_front();
			}
		}
		else if (left.size() > 0)
		{
			result.push_back(left.front());
			left.pop_front();
		}
		else if (right.size() > 0)
		{
			result.push_back(right.front());
			right.pop_front();
		}
	}
	return (result);
}

std::list<int>	PmergeMe::mergeSort(std::list<int> &nums)
{
	if (nums.size() <= 1)
		return (nums);
	std::list<int> left;
	std::list<int> right;
	std::list<int>::iterator it = nums.begin();
	std::list<int>::iterator ite = nums.end();
	std::size_t i = 0;
	while (it != ite)
	{
		if (i < nums.size() / 2)
			left.push_back(*it);
		else
			right.push_back(*it);
		++it;
		++i;
	}
	left = mergeSort(left);
	right = mergeSort(right);
	return (merge(left, right));
}

// Fonction pour fusionner deux sous-vecteurs triés en un seul sous-vecteur trié
void PmergeMe::merge(int left, int mid, int right)
{
	int i = left;
	int j = mid + 1;
	std::vector<int> temp;  // Vecteur temporaire pour stocker les éléments fusionnés

	while (i <= mid && j <= right)
	{
		if (_vector[i] <= _vector[j])
			temp.push_back(_vector[i++]);
		else
			temp.push_back(_vector[j++]);
	}

	// Ajout des éléments restants du premier sous-vecteur
	while (i <= mid)
		temp.push_back(_vector[i++]);

	// Ajout des éléments restants du second sous-vecteur
	while (j <= right)
		temp.push_back(_vector[j++]);

	// Copie des éléments fusionnés dans le vecteur original
	for (int k = left; k <= right; k++)
		_vector[k] = temp[k - left];
}

// Fonction de tri merge-insert récursive
void PmergeMe::mergeSort(int left, int right)
{
	if (left < right) {
		// Calcul du milieu pour diviser le vecteur en deux parties
		int mid = (left + right) / 2;

		// Appel récursif sur la première moitié
		mergeSort(left, mid);

		// Appel récursif sur la deuxième moitié
		mergeSort(mid + 1, right);

		// Fusion des deux moitiés triées
		merge(left, mid, right);
	}
}

const char *PmergeMe::InvalidInputException::what() const throw() { return "Error: invalid character in input"; }

const char *PmergeMe::NegativeNumberException::what() const throw() { return "Error: negative numbers are not allowed"; }

const char *PmergeMe::OverflowException::what() const throw() { return "Error: overflow detected"; }