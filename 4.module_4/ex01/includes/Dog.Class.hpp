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

# include "Animal.Class.hpp"
# include "Brain.Class.hpp"
# include <string>

class Dog : virtual public Animal
{
	private:
		Brain	*brain;
	public:
		Dog &operator=(const Dog &rhs);
		Dog(const Dog &Copy);
		virtual ~Dog(void);
		Dog(void);

		void 	makeSound(void) const;
		Brain	*getIdea(void) const;
};

#endif
