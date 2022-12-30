#ifndef EASYFIND_CLASS_HPP
# define EASYFIND_CLASS_HPP

# include <exception>
# include <algorithm>
# include <vector>

class EmptyArrayException : public std::exception
{
	public:
		virtual const char	*what() const throw() {return ("Empty array\n");}
};

class ElementNotFoundException : public std::exception
{
	public:
		virtual const char	*what() const throw() {return ("Element not found in container\n");}

};

template <typename T>
typename T::iterator	easyfind(T &array, int value)
{
	typename T::iterator	it;

	if (array.empty())
		throw EmptyArrayException();
	it = std::find(array.begin(), array.end(), value);
	if (it != array.end())
		return (it);
	throw ElementNotFoundException();
}

#endif