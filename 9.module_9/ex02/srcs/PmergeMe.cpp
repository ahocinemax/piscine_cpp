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

std::set<int> &PmergeMe::getData()  { return _set; }