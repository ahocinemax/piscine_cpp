/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.Class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 00:00:10 by ahocine           #+#    #+#             */
/*   Updated: 2022/11/24 00:00:14 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_CLASS_HPP
# define CAT_CLASS_HPP

#include "Animal.Class.hpp"
#include "Brain.Class.hpp"

class Cat : virtual public Animal
{
	private:
		Brain	*brain;

	public:
		Cat &operator=(const Cat &rhs);
		Cat(const Cat &Copy);
		~Cat(void);
		Cat(void);

		void makeSound(void) const;
};

#endif
