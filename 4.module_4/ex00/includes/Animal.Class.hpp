/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.Class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 23:59:36 by ahocine           #+#    #+#             */
/*   Updated: 2022/11/23 23:59:50 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_CLASS_HPP
# define ANIMAL_CLASS_HPP

# include <string>
# include <iostream>

class Animal
{
	protected:
		std::string type;

	public:
		Animal &operator=(const Animal &rhs);
		Animal(const Animal &Copy);
		virtual ~Animal(void);
		Animal(void);

		virtual const std::string &getType(void) const;
		virtual void makeSound(void) const;
};

#endif
