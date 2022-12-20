/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.Class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 22:54:17 by ahocine           #+#    #+#             */
/*   Updated: 2022/11/26 22:54:25 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_CLASS_HPP
# define INTERN_CLASS_HPP

# include <string>
# include <iostream>

class Form;
class Intern
{
	public:
		Intern(void);
		~Intern(void);

		Form	*makeForm(const std::string &form, const std::string &target) const;

		class InvalidFormException : public std::exception
		{
			public:
				const char *what(void) const throw();
		};
};

#endif
