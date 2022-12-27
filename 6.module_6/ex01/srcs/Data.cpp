#include "../includes/Data.Class.hpp"

Data &Data::operator=(const Data &Copy)
{
	if (Copy.getVal() == this->val)
		return (*this);
	this->val = Copy.getVal();
	std::cout << "Data assignement operator called" << std::endl;
	return (*this);
}

Data::Data(char c) : val(c)
{
	std::cout << "Full data constructor called with value: " << c << std::endl;
}

Data::Data(const Data &Copy)
{
	if (Copy.getVal() == this->val)
		return ;
	this->val = Copy.getVal();
	std::cout << "Data copy constructor called" << std::endl;
}

Data::Data(void) : val('a')
{
	std::cout << "Default data constructor called with value: 'a'" << std::endl;
}

Data::~Data(void)
{
	std::cout << "Data destructor called" << std::endl;
}

const char	&Data::getVal(void) const
{
	return (this->val);
}

uintptr_t	serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data	*deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}
