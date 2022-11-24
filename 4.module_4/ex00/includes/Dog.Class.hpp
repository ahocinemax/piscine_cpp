/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.Class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 23:59:59 by ahocine           #+#    #+#             */
/*   Updated: 2022/11/24 00:00:01 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_CLASS_HPP
# define DOG_CLASS_HPP

# include <string>
# include "Animal.Class.hpp"

class Dog : virtual public Animal
{
	public:
		Dog &operator=(const Dog &rhs);
		Dog(const Dog &Copy);
		~Dog(void);
		Dog(void);

		void makeSound(void) const;
};

#endif
