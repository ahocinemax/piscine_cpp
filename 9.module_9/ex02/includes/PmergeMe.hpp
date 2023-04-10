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
		double				getElapsedVector() const;
		double				getElapsedList() const;

	private:
		std::list<int>		_list;
		std::vector<int>	_vector;
		double 				_elapsedVector;
		double 				_elapsedList;

		std::list<int> parse_input(const std::string& input);

		template <class T>
		T merge_sort(T& nums)
		{
			if (nums.size() <= 1)
				return (nums);

			T left;
			T right;
			typename T::iterator it = nums.begin();

			for (size_t i = 0; i < nums.size() / 2; ++i)
			{
				left.push_back(*it);
				++it;
			}
			for (size_t i = nums.size() / 2; i < nums.size(); ++i)
			{
				right.push_back(*it);
				++it;
			}

			left = merge_sort(left);
			right = merge_sort(right);

			return (merge(left, right));
		}

		template <class T>
		T merge(T& left, T& right)
		{
			T merged;

			typename T::iterator it_left = left.begin();
			typename T::iterator it_right = right.begin();

			while (it_left != left.end() && it_right != right.end())
			{
				if (*it_left < *it_right)
				{
					merged.push_back(*it_left);
					++it_left;
				}
				else
				{
					merged.push_back(*it_right);
					++it_right;
				}
			}
			return (merged);
		}
};

#endif