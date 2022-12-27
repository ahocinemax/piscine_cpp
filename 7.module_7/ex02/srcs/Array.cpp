#include "../includes/Array.Class.hpp"

template <typename T>
Array<T>::Array(void) : size(0), array(new T[0])
{
	std::cout << "Default constructor called" << std::endl;
}

template <typename T>
Array<T>::Array(size_t n) : size(n), array(new T[n]) 
{
	std::cout << "Full constructor called" << std::endl;
}

template <typename T>
Array<T>::Array(const Array &Copy)
{
	if (this != &Copy)
	{
		this->size = Copy->size;
		this->array = new T[Copy->size];
		for (size_t i = 0 ; i < Copy->size ; i++)
			this->array[i] = Copy.array[i];
	}
	std::cout << "Copy constructor called" << std::endl;
}

template <typename T>
Array<T>::~Array(void)
{
    delete [] this->array;
	std::cout << "Destructor called" << std::endl;

}

template <typename T>
Array<T> &Array<T>::operator[](size_t index)
{
	if (this->size < 0 || this->size > index - 1)
		throw OutOfRangeException();
	else
		return (this->array[index]);
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &rhs)
{
    if (this != &rhs)
	{
		this->size = rhs->size;
		this->array = new T[rhs->size];
		for (size_t i = 0 ; i < rhs->size ; i++)
			this->array[i] = rhs.array[i];
	}
	std::cout << "Assignation operator called" << std::endl;
}

template <typename T>
size_t	Array<T>::getSize(void) const
{
	return (this->size);
}

template <typename T>
const char *Array<T>::OutOfRangeException::what() const throw()
{
	return ("error: Value is out of range");
}
