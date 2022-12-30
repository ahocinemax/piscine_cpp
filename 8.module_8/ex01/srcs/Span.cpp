#include "../includes/Span.Class.hpp"
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <numeric>

Span::Span(const unsigned int &nb) : size(nb)
{
	std::cout << "Span full constructor called with : " << nb << std::endl;
}

Span::Span(const Span &Copy) : size(Copy.getSize()), tab(Copy.tab)
{
	std::cout << "Span copy constructor called" << std::endl;
}

Span &Span::operator=(const Span &rhs)
{
	if (this != &rhs)
	{
		this->size = rhs.getSize();
		this->tab = rhs.tab;
	}
	std::cout << "Span copy constructor called" << std::endl;
	return (*this);
}

Span::~Span(void)
{
	std::cout << "Span destructor called" << std::endl;
}

unsigned int    Span::getSize() const
{
	return (this->size);
}

void 	Span::addNumber(int nb)
{
	if (this->tab.size() < this->size)
		tab.push_back(nb);
	else
		throw Span::ArrayFullException();
}

void	Span::addNumber(const std::vector<int>::iterator &start, const std::vector<int>::iterator &end)
{
	int sizeToAdd = std::distance(start, end);
	if (this->tab.size() + sizeToAdd > this->size)
	{
		this->tab.insert(this->tab.end(), start, start + (this->size - this->tab.size()));
		throw Span::ArrayFullException();
	}
	this->tab.insert(this->tab.end(), start, end);
}

unsigned int	Span::shortestSpan() const
{
	std::vector<int>    tmp;
	int (*iabs)(int) =  &std::abs;

	if (this->tab.size() < 2)
		throw Span::EmptyArrayException();
	std::adjacent_difference(this->tab.begin(), this->tab.end(), std::back_inserter(tmp));
	std::transform(tmp.begin(), tmp.end(), tmp.begin(), iabs);
	return (*std::min_element(tmp.begin(), tmp.end()));
}

unsigned int	Span::longestSpan() const
{
	std::vector<int>    tmp;
	int (*iabs)(int) =  &std::abs;

	if (this->tab.size() < 2)
		throw Span::EmptyArrayException();
	std::adjacent_difference(this->tab.begin(), this->tab.end(), std::back_inserter(tmp));
	std::transform(tmp.begin(), tmp.end(), tmp.begin(), iabs);
	return (*std::max_element(tmp.begin(), tmp.end()));
}
