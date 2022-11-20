#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

# include <string>
# include <iostream>

class Fixed
{
	private:
		int					number;
		static const int	bits = 8;

	public:
		Fixed &operator=(const Fixed &rhs);
		void	setRawBits(const int raw);
		int	getRawBits(void) const;
		Fixed(const Fixed &copy);
		~Fixed();
		Fixed();
};

#endif