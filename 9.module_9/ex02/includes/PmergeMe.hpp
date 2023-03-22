#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>

#include <iostream>
#include <set>
#include <map>
#include <cstdlib>
#include <stdlib.h>
#include <ctime>
#include <sstream>
#include <string>

class PmergeMe
{
	public:
		PmergeMe() {}
		PmergeMe(const std::string& input);
		~PmergeMe() {}

		size_t				size() const { return _set.size(); };
		void				print() const;
		void				add(int val);
		std::set<int>		&getData();
		std::map<int, int>	&getMap() { return _map; }
		void				sort();
		bool				parse(std::string str);
		bool				parseList(int argc, char **argv);

	private:
		std::set<int>		_set;
		std::map<int, int>	_map;

		std::map<int, int> parse_input(const std::string& input);
		std::map<int, int> merge_sort(std::map<int, int>& nums);
		std::map<int, int> merge(std::map<int, int>& left, std::map<int, int>& right);
};

#endif