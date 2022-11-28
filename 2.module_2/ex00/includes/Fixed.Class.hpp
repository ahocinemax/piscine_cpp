/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.Class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 00:04:13 by ahocine           #+#    #+#             */
/*   Updated: 2022/11/17 00:05:05 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		Fixed(const Fixed &copy);
		~Fixed(void);
		Fixed(void);

		Fixed	&operator=(const Fixed &rhs);
		void	setRawBits(const int raw);
		int		getRawBits(void) const;
};

#endif