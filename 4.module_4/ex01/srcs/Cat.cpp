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
	this->brain = new Brain(*rhs.brain);
	return (*this);
}

Cat::Cat(const Cat &Copy) : Animal(Copy)
{
	this->brain = new Brain(*Copy.brain);
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat::Cat(void) : brain(new Brain())
{
	std::cout << "Cat default constructor called" << std::endl;
	type = "Cat";
}

Cat::~Cat(void)
{
	delete (brain);
	std::cout << "Cat destructor called" << std::endl;
}

Brain	*Cat::getIdea(void) const
{
	return (this->brain);
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow" << std::endl;
}
