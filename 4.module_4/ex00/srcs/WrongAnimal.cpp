/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 00:00:57 by ahocine           #+#    #+#             */
/*   Updated: 2022/11/24 00:00:58 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongAnimal.Class.hpp"

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &rhs)
{
	std::cout << "WrongAnimal assignement oeprator called" << std::endl;
	type = rhs.type;
	return (*this);
}

WrongAnimal::WrongAnimal(const WrongAnimal &Copy)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	type = Copy.type;
}

WrongAnimal::WrongAnimal(void) : type("Unknown type")
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}


const std::string &WrongAnimal::getType(void) const
{
	return (type);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "Default Sound: (UwU)";
}
