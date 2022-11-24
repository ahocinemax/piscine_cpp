/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.Class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 00:00:10 by ahocine           #+#    #+#             */
/*   Updated: 2022/11/24 00:00:14 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_CLASS_HPP
# define WRONGCAT_CLASS_HPP

#include "WrongAnimal.Class.hpp"

class WrongCat : virtual public WrongAnimal
{
	public:
		WrongCat &operator=(const WrongCat &rhs);
		WrongCat(const WrongCat &Copy);
		~WrongCat(void);
		WrongCat(void);

		void makeSound(void) const;
};

#endif
