/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 00:00:37 by ahocine           #+#    #+#             */
/*   Updated: 2022/11/24 00:00:39 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.Class.hpp"

Dog &Dog::operator=(const Dog &rhs)
{
	std::cout << "Dog assignement oeprator called" << std::endl;
	Animal::operator=(rhs);
	this->brain = new Brain(*rhs.brain);
	return (*this);
}

Dog::Dog(const Dog &Copy) : Animal(Copy)
{
	this->brain = new Brain(*Copy.brain);
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::Dog(void) : brain(new Brain())
{
	std::cout << "Dog default constructor called" << std::endl;
	type = "Dog";
}

Dog::~Dog(void)
{
	delete (brain);
	std::cout << "Dog destructor called" << std::endl;
}

void	Dog::makeSound(void) const
{
	std::cout << "WoUUuFf" << std::endl;
}
