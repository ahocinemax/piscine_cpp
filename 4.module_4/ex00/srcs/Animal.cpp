/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 00:00:57 by ahocine           #+#    #+#             */
/*   Updated: 2022/11/24 00:00:58 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.Class.hpp"

Animal &Animal::operator=(const Animal &rhs)
{
	std::cout << "Animal assignement oeprator called" << std::endl;
	type = rhs.type;
	return (*this);
}

Animal::Animal(const Animal &Copy)
{
	std::cout << "Animal copy constructor called" << std::endl;
	type = Copy.type;
}

Animal::Animal(void) : type("Unknown type")
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor called" << std::endl;
}

const std::string &Animal::getType(void) const
{
	return (type);
}

void	Animal::makeSound(void) const
{
	std::cout << "Default Sound: (UwU)" << std::endl;
}
