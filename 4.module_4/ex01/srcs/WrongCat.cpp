/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 00:00:49 by ahocine           #+#    #+#             */
/*   Updated: 2022/11/24 00:00:50 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongCat.Class.hpp"

WrongCat &WrongCat::operator=(const WrongCat &rhs)
{
	std::cout << "WrongCat assignement oeprator called" << std::endl;
	WrongAnimal::operator=(rhs);
	return (*this);
}

WrongCat::WrongCat(const WrongCat &Copy) : WrongAnimal(Copy)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat::WrongCat(void)
{
	std::cout << "WrongCat default constructor called" << std::endl;
	type = "WrongCat";
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destructor called" << std::endl;
}

void	WrongCat::makeSound(void) const
{
	std::cout << "NYAAaAa" << std::endl;
}
