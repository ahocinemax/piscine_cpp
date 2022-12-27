#ifndef ARRAY_CLASS_HPP
# define ARRAY_CLASS_HPP

#include <iostream>
#include <string>

template <typename T>
class Array
{
	private:
		size_t	size;
		T		*array;

	public:
		Array(const Array &Copy);
		Array(size_t n);
		~Array(void);
		Array(void);

		Array &operator[](size_t index);
		Array &operator=(const Array &rhs);
		size_t	getSize(void) const;

		class OutOfRangeException : virtual public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

#endif
