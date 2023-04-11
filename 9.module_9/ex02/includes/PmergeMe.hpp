#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <list>
# include <cstdlib>
# include <stdlib.h>
# include <ctime>
# include <sstream>
# include <string>

class PmergeMe
{
	public:
		PmergeMe();
		~PmergeMe();

		void				print() const;
		void				sort_containers();

		bool				parse(std::string str);
		bool				parseList(int argc, char **argv);

		std::vector<int>	&getVector();
		std::list<int>		&getList();
		double				getTimeVector() const;
		double				getTimeList() const;

	private:
		std::list<int>		_list;
		std::vector<int>	_vector;
		double 				_timeVector;
		double 				_timeList;

		std::list<int>	parse_input(const std::string& input);

		std::list<int>	merge(std::list<int> &left, std::list<int> &right);

		std::list<int>	mergeSort(std::list<int> &nums);

		void			merge(int left, int mid, int right);

		void			mergeSort(int left, int right);
};

#endif
