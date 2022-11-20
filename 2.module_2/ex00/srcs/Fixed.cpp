#include "../includes/Fixed.Class.hpp"

Fixed::Fixed(void)
{
    this->number = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
    *this = copy;
    std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}

Fixed   &Fixed::operator=(const Fixed &rhs)
{
    std::cout << "Copy assignement operator called" << std::endl;
    this->number = rhs.getRawBits();
    return (*this);
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->number);
}

void    Fixed::setRawBits(int const raw)
{
    this->number = raw;
    return ;
}
