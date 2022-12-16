/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 00:00:49 by ahocine           #+#    #+#             */
/*   Updated: 2022/11/24 00:00:50 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.Class.hpp"

Cat &Cat::operator=(const Cat &rhs)
{
	std::cout << "Cat assignement oeprator called" << std::endl;
	Animal::operator=(rhs);
	return (*this);
}

Cat::Cat(const Cat &Copy) : Animal(Copy)
{
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat::Cat(void)
{
	std::cout << "Cat default constructor called" << std::endl;
	type = "Cat";
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow" << std::endl;
}
