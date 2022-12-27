#ifndef ITER_CLASS_HPP
# define ITER_CLASS_HPP

#include <iostream>
#include <string>

template <typename T>
void	iter(T *array, size_t size, void (*f)(const T&))
{
	for (size_t i = 0 ; i < size ; i++)
		(*f)(array[i]);
}

template <typename T>
void	ft_print(const T &out)
{
	std::cout << out << std::endl;
}

#endif
