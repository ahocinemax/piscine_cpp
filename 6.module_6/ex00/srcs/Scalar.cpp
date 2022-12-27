#include "../includes/Scalar.Class.hpp"
#include <stdlib.h>

Scalar::Scalar(std::string &str) : str(str)
{
	std::cout << "Scalar full constructor called" << std::endl;
	try
	{
		if (str.empty())
			throw Scalar::InvalidInputException();
		else if (str.size() == 1)
		{
			if (isdigit(str.front()))
			{
				this->entier = static_cast<int>(strtol(str.c_str(), NULL, 10));
				this->type = intType;
			}
			else
			{
				this->lettre = str.front();
				this->type = charType;
			}
		}
		else
		{
			double value = strtod(str.c_str(), NULL);
			if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
			{
				if (str.back() == 'f' && (value > std::numeric_limits<float>::min() && value < std::numeric_limits<float>::max()))
				{
					this->decimal = static_cast<float>(value);
					this->type = floatType;
				}
				else
				{
					this->precision = value;
					this->type = doubleType;
				}
			}
			else
			{
				this->entier = static_cast<int>(value);
				this->type = intType;
			}
		}
	}
	catch (const std::exception &e)
	{
		switch (this->type)
		{
			case doubleType:
				std::cerr << "doubleType" << std::endl;
			case intType:
				std::cerr << "intType" << std::endl;
			case charType:
				std::cerr << "charType" << std::endl;
			case floatType:
				std::cerr << "floatType" << std::endl;
			default:
				break;
		}
		std::cerr << e.what() << std::endl;
	}
}

Scalar::Scalar(const Scalar &other) : str(other.str), decimal(other.decimal), entier(other.entier),
										lettre(other.lettre), precision(other.precision)
{
	std::cout << "Scalar copy constructor called" << std::endl;
}

Scalar &Scalar::operator=(const Scalar &rhs)
{
	if (&rhs == this)
		return (*this);
	decimal = rhs.decimal;
	str = rhs.str;
	entier = rhs.entier;
	lettre = rhs.lettre;
	precision = rhs.precision;
	std::cout << "Scalar assignation operator called" << std::endl;
	return (*this);
}

Scalar::~Scalar(void)
{
	std::cout << "Scalar destructor called" << std::endl;
}

double	Scalar::toDouble(void) const
{
	switch (type)
	{
		case doubleType:
			return (this->precision);
		case intType:
			return (static_cast<double>(this->entier));
		case charType:
			return (static_cast<double>(this->lettre));
		case floatType:
			return (static_cast<double>(this->decimal));
		default:
			throw Scalar::InvalidInputException();
	}
}

float	Scalar::toFloat(void) const
{
	switch (type)
	{
		case intType:
			return (static_cast<float>(this->entier));
		case charType:
			return (static_cast<float>(this->lettre));
		case floatType:
			return (this->decimal);
		case doubleType:
			return (static_cast<float>(this->precision));
		default:
			throw Scalar::InvalidInputException();
	}
}

char	Scalar::toChar(void) const
{
	char	c;

	try
	{
		switch (this->type)
		{
			case intType:
				c = static_cast<char>(this->entier);
				if (!isprint(c) || this->entier < 32 || this->entier > 126)
					throw Scalar::NonPrintableException();
				else
					return (c);
			case floatType:
				c = static_cast<char>(this->decimal);
				if (isnan(this->decimal) || isinf(this->decimal)
					|| this->decimal > std::numeric_limits<char>::max() || this->decimal < std::numeric_limits<char>::min())
					throw Scalar::ImpossibleException();
				else if (!isprint(c) || this->entier < 32 || this->entier > 126)
					throw Scalar::NonPrintableException();
				else
					return (c);

			case doubleType:
				c = static_cast<char>(this->precision);
				if (isnan(this->precision) || isinf(this->precision)
					|| this->precision > std::numeric_limits<char>::max() || this->precision < std::numeric_limits<char>::min())
					throw Scalar::ImpossibleException();
				else if (!isprint(c) || this->entier < 32 || this->entier > 126)
					throw Scalar::NonPrintableException();
				else
					return (c);
		
			default:
				return (this->lettre);
		}
	}	
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}
	return (0);
}

int	Scalar::toInt(void) const
{
	int	val;

	try
	{
		switch (this->type)
		{
			case charType:
				return (static_cast<int>(lettre));

			case floatType:
				val = static_cast<int>(this->decimal);
				if (isnan(this->decimal) || isinf(this->decimal) || this->decimal > std::numeric_limits<int>::max()
					|| this->decimal < std::numeric_limits<int>::min())
					throw Scalar::ImpossibleException();
				else
					return (val);

			case doubleType:
				val = static_cast<int>(this->precision);
				if (isnan(this->precision) || isinf(this->precision)
					|| this->precision > std::numeric_limits<int>::max() || this->precision < std::numeric_limits<int>::min())
					throw Scalar::ImpossibleException();
				else
					return (val);

			default:
				return (this->entier);
		}
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what();
		return (346513);
	}
}

int		Scalar::getType(void) const
{
	return (this->type);
}

const char	*Scalar::InvalidInputException::what() const throw()
{
	return ("\e[31minvalid input\e[0m");
}

const char	*Scalar::ImpossibleException::what() const throw()
{
	return ("\e[31mimpossible conversion\e[0m");
}

const char	*Scalar::NonPrintableException::what() const throw()
{
	return ("\e[31mcannot display restult\e[0m");
}

std::ostream& operator<<(std::ostream& out, const Scalar& rhs)
{
	if (rhs.getType() >= 0 && rhs.getType() <= 3)
	{
		std::cout << "int: ";
		if (rhs.toInt() != 346513)
			std::cout << rhs.toInt() << std::endl;
		else
			std::cout << std::endl;
		std::cout << "char: " << rhs.toChar() << std::endl;
		std::cout << "double: " << rhs.toDouble() << std::endl;
		std::cout << "float: " << rhs.toFloat() << "f\n";
	}
	return (out);
}
