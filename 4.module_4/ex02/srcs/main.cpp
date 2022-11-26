/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <marvin@45.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 04:50:46 by ahocine           #+#    #+#             */
/*   Updated: 2022/11/24 04:50:48 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.Class.hpp"
#include "../includes/Dog.Class.hpp"

int main()
{
	int k = 0;
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;
	delete i;

	Animal * arrayAnimal[10];
	while (k < 5)
	{
		arrayAnimal[k++] = new Dog();
	}
	while (k < 10)
	{
		arrayAnimal[k++] = new Cat();
	}
	k = 0;
	while (k < 10)
	{
		std::cout << "Animal [" << k << "] : " << arrayAnimal[k]->getType() << std::endl;
		arrayAnimal[k++]->makeSound();
	}
	k = 0;
	while(k < 10)
	{
		delete arrayAnimal[k++];
	}
	
	Cat chatTmp;
	{
		Cat tmp = chatTmp;
	}
	Dog chienTmp;
	{
		Dog tmp = chienTmp;
	}

	return (0);
}
