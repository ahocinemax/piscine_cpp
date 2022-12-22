/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@stduent.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:45:20 by ahocine           #+#    #+#             */
/*   Updated: 2022/12/20 16:45:37 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Base.Class.hpp"
#include "../includes/A.Class.hpp"
#include "../includes/B.Class.hpp"
#include "../includes/C.Class.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

Base *generate(void)
{
	std::srand(std::time(NULL));
	switch (rand() % 3)
	{
		case 0:
			std::cout << "A generated" << std::endl;
			return (new A());

		case 1:
			std::cout << "B generated" << std::endl;
			return (new B());

		case 2:
			std::cout << "C generated" << std::endl;
			return (new C());

		default:
			return (new C());
	}
}

void	indentify(Base *ptr)
{
	std::cout << "Base pointer is: ";
	if (dynamic_cast<A*>(ptr))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(ptr))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(ptr))
		std::cout << "C" << std::endl;
	else
		std::cout << "bad cast" << std::endl;
}

void	indentify(Base &ref)
{
	std::cout << "Base reference is: ";
	if (dynamic_cast<A*>(&ref))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(&ref))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(&ref))
		std::cout << "C" << std::endl;
	else
		std::cout << "bad cast" << std::endl;
}

int main(void)
{
	srand(time(NULL));
	std::cout << "--------- pointer part ---------" << std::endl;
	Base	*ptr = generate();
	indentify(ptr);

	std::cout << "\n--------- pointer part ---------" << std::endl;
	Base	*tmp = generate();
	Base	&ref = *tmp;
	indentify(ref);
	
	return (0);
}
