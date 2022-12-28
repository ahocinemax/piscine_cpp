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
		Array(void) : size(0), array(new T[0]) {return ;}

		Array(size_t n) : size(n), array(new T[n]) {return ;}

		Array(const Array &Copy)
		{
			this->size = Copy.size;
			this->array = new T[Copy.size];
			for (size_t i = 0 ; i < Copy.size ; i++)
				this->array[i] = Copy.array[i];
		}

		~Array(void)
		{
			delete [] this->array;
		}

		size_t getSize(void) const {return this->size;}

		Array &operator=(const Array &rhs)
		{
			if (this != &rhs)
			{
				this->~Array();
				this->size = rhs.size;
				this->array = new T[rhs.size];
				for (size_t i = 0 ; i < rhs.size ; i++)
					this->array[i] = rhs.array[i];
			}
			return (*this);
		}

		T &operator[](size_t index)
		{
			if (index >= this->size)
				throw OutOfRangeException();
			return (this->array[index]);
		}

		class OutOfRangeException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("error: Value is out of range");
				}
		};
};

#endif
