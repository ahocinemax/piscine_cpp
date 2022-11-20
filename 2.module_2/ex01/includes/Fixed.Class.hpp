#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

# include <string>
# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int					number;
		static const int	bits = 8;

	public:
		Fixed &operator =(const Fixed &rhs);
		Fixed(const Fixed &copy);
		Fixed(const float param);
		Fixed(const int param);
		~Fixed(void);
		Fixed(void);

		void	setRawBits(const int raw);
		int		getRawBits(void) const;
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream &operator<<(std::ostream &out, Fixed const &rhs);

#endif