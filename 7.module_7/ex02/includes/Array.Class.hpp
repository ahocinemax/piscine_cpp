#ifndef ITER_CLASS_HPP
# define ITER_CLASS_HPP

#include <iostream>
#include <string>

template <typename T>
class Array
{
	private:
		size_t	size;
		T		*array;
	public:
		Array(void);
		Array(size_t n);
		Array(const Array &Copy);
		~Array(void);

		Array &operator=(const Array &rhs)
};

#endif
