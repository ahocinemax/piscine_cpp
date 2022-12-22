#include "../includes/Scalar.Class.hpp"

Scalar::Scalar(std::string &str) : str(str)
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
		char *LongRest = 0;
		long LongVal = strtol(str.c_str(), &LongRest, 10);
		char *DoubleRest = 0;
		long DoubleVal = strtol(str.c_str(), &DoubleRest, 10);
		if (*LongRest)
		{
			if (*DoubleRest)
			{
				if (*DoubleRest == 'f')
				{
					this->decimal = static_cast<float>(DoubleVal);
					this->type = floatType;
				}
				else
					throw Scalar::InvalidInputException();
			}
			else
			{
				this->precision = DoubleVal;
				this->type = doubleType;
			}
		}
		else
		{
			if (LongVal < std::numeric_limits<int>::min() || LongVal > std::numeric_limits<int>::max())
				throw Scalar::InvalidInputException();
			else
			{
				this->entier = static_cast<int>(LongVal);
				this->type = intType;
			}
		}
	}
	std::cout << "Scalar full constructor called" << std::endl;
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
	return (0);
}

float	Scalar::toFloat(void) const
{
	return (0);
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
				if (!isprint(c))
					throw Scalar::NonPrintableException();
				else
					return (c);
			
			case floatType:
				c = static_cast<char>(this->decimal);
				if (isnan(this->decimal) || isinf(this->decimal)
					|| this->decimal > std::numeric_limits<char>::max() || this->decimal < std::numeric_limits<char>::min())
					throw Scalar::ImpossibleException();
				else if (!isprint(c))
					throw Scalar::NonPrintableException();
				else
					return (c);

			case doubleType:
				c = static_cast<char>(this->precision);
				if (isnan(this->precision) || isinf(this->precision)
					|| this->precision > std::numeric_limits<char>::max() || this->precision < std::numeric_limits<char>::min())
					throw Scalar::ImpossibleException();
				else if (!isprint(c))
					throw Scalar::NonPrintableException();
				else
					return (c);
		
			default:
				return (this->lettre);
		}
	}	
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
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
				if (isnan(this->decimal) || isinf(this->decimal)
					|| this->decimal > std::numeric_limits<int>::max() || this->decimal < std::numeric_limits<int>::min())
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
		std::cerr << e.what() << '\n';
	}
	return (-1);
}

const char	*Scalar::InvalidInputException::what() const throw()
{
	return ("\e[31minvalid input\e[0m\n");
}

const char	*Scalar::ImpossibleException::what() const throw()
{
	return ("\e[31mimpossible conversion\e[0m\n");
}

const char	*Scalar::NonPrintableException::what() const throw()
{
	return ("\e[31mcannot display restult\e[0m\n");
}

std::ostream& operator<<(std::ostream& out, const Scalar& rhs)
{
	std::cout << "int: " << rhs.toInt() << std::endl;
	std::cout << "char: " << rhs.toChar() << std::endl;
	std::cout << "double: " << rhs.toDouble() << std::endl;
	std::cout << "float: " << rhs.toFloat() << std::endl;
	return (out);
}