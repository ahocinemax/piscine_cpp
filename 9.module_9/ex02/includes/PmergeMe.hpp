#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>

#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <cstdlib>
#include <stdlib.h>
#include <ctime>
#include <sstream>
#include <string>

class PmergeMe
{
	public:
		PmergeMe() {}
		~PmergeMe() {}

		void				print() const;
		void				add(int val);
		std::set<int>		&getData();
		std::map<int, int>	&getMap();
		void				sort();
		bool				parse(std::string str);

	private:
		std::set<int>		_set;
		std::map<int, int>	_map;
};

#endif