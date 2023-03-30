#include "PmergeMe.hpp"

PmergeMe::PmergeMe(const std::string& input)
{
	// convert input string to map of integers
	std::map<int, int>	nums = parse_input(input);

	// sort the map using merge sort
	nums = merge_sort(nums);
}

std::map<int, int> PmergeMe::merge(std::map<int, int>& left, std::map<int, int>& right)
{
	std::map<int, int> merged;

	std::map<int, int>::iterator it_left = left.begin();
	std::map<int, int>::iterator it_right = right.begin();

	while (it_left != left.end() && it_right != right.end())
	{
		if (it_left->first <= it_right->first)
		{
			merged[it_left->first] += it_left->second;
			++it_left;
		}
		else
		{
			merged[it_right->first] += it_right->second;
			++it_right;
		}
	}

	for (; it_left != left.end(); ++it_left)
		merged[it_left->first] += it_left->second;
	for (; it_right != right.end(); ++it_right)
		merged[it_right->first] += it_right->second;

	return (merged);
}

std::map<int, int> PmergeMe::merge_sort(std::map<int, int>& nums)
{
	if (nums.size() <= 1)
		return nums;

	std::map<int, int> left, right;
	std::map<int, int>::iterator it = nums.begin();
	int middle = nums.size() / 2;
	for (int i = 0; i < middle; ++i)
	{
		left[it->first] = it->second;
		++it;
	}
	for (; it != nums.end(); ++it)
		right[it->first] = it->second;

	left = merge_sort(left);
	right = merge_sort(right);

	return (merge(left, right));
}

std::map<int, int> PmergeMe::parse_input(const std::string& input)
{
	std::map<int, int>	nums;
	std::stringstream	ss(input);
	int					num;

	while (ss >> num)
		nums[num]++;
	return (nums);
}

void	PmergeMe::add(int val)
{
	_set.insert(val);
	std::cout << " " << val;
}

void	PmergeMe::print() const
{
	std::set<int>::const_iterator it;
	std::cout << "After:   ";
	for (it = _set.begin(); it != _set.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
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
		add(val);
	}
	std::cout << std::endl;
	return (true);
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
		add(val);
	}
	std::cout << std::endl;
	return (true);
}

std::set<int> &PmergeMe::getData()  { return _set; }

size_t PmergeMe::size() const { return _set.size(); }

std::map<int, int>	&PmergeMe::getMap() { return _map; }
