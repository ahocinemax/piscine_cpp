/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 00:01:07 by ahocine           #+#    #+#             */
/*   Updated: 2022/11/24 00:01:09 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongCat.Class.hpp"
#include "../includes/Dog.Class.hpp"
#include "../includes/Cat.Class.hpp"

int main()
{
	const WrongAnimal	*wrong	= new WrongCat();
	const Animal		*meta	= new Animal();
	const Animal		*j		= new Dog();
	const Animal		*i		= new Cat();

	std::cout << std::endl;

	std::cout << wrong->getType() << " " << std::endl;
	std::cout << meta->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	std::cout << std::endl;

	i->makeSound();
	j->makeSound();
	meta->makeSound();
	wrong->makeSound();

	std::cout << std::endl;

	delete wrong;
	delete meta;
	delete i;
	delete j;

	return 0;
}