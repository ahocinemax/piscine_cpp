/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.Class.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 23:59:36 by ahocine           #+#    #+#             */
/*   Updated: 2022/11/23 23:59:50 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_CLASS_HPP
# define WRONGANIMAL_CLASS_HPP

# include <string>
# include <iostream>

class WrongAnimal
{
	protected:
		std::string type;

	public:
		WrongAnimal &operator=(const WrongAnimal &rhs);
		WrongAnimal(const WrongAnimal &Copy);
		virtual ~WrongAnimal(void);
		WrongAnimal(void);

		virtual const std::string &getType(void) const;
		virtual void makeSound(void) const;
};

#endif
