#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>

#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <string>

class PmergeMe
{
	public:
		PmergeMe() {}
		~PmergeMe() {}

		void add(int val);
		void sort();
		void print() const;
		std::set<int> &getData();

	private:
		std::set<int>		_set;
		std::map<int, int>	_map;
};

#endif