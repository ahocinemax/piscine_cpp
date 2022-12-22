#ifndef SCALAR_CLASS_HPP
# define SCALAR_CLASS_HPP

# include <string>
# include <iostream>
# include <limits>
# include <iomanip>
# include <math.h>

class Scalar
{
	private:
		enum ValType {charType, intType, floatType, doubleType} type;
		double		precision;
		float		decimal;
		char		lettre;
		int			entier;
		std::string	&str;

	public:
		Scalar &operator=(const Scalar &rhs);
		Scalar(const Scalar &other);
		Scalar(std::string &str);
		~Scalar(void);

		double	toDouble(void) const;
		float	toFloat(void) const;
		char	toChar(void) const;
		int		toInt(void) const;

		class InvalidInputException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class NonPrintableException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class ImpossibleException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

std::ostream& operator<<(std::ostream& out, const Scalar& rhs);

#endif