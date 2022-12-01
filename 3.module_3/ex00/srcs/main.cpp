/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 16:45:47 by ahocine           #+#    #+#             */
/*   Updated: 2022/10/23 17:57:05 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.Class.hpp"

int main()
{
	{
		ClapTrap clapTrap("ClapTrapy");

		std::cout << "------------------" << std::endl;
		std::cout << "initial stats:" << std::endl;
		std::cout << "energy points: " << clapTrap.getEnergyPoints() << std::endl;
		std::cout << "attack damage: " << clapTrap.getAttackDamage() << std::endl;
		std::cout << "hit points   : " << clapTrap.getHitPoints() << std::endl;
		std::cout << "------------------" << std::endl;

		clapTrap.attack("enemy");

		clapTrap.takeDamage(5);

		clapTrap.beRepaired(5);

		clapTrap.takeDamage(20);

		clapTrap.attack("enemy2");
		clapTrap.beRepaired(5);

		std::cout << clapTrap.getHitPoints() << std::endl;
	}
	ClapTrap clapTrap2("damian");

	std::cout << "------------------" << std::endl;
	std::cout << "initial stats:" << std::endl;
	std::cout << "energy points: " << clapTrap2.getEnergyPoints() << std::endl;
	std::cout << "attack damage: " << clapTrap2.getAttackDamage() << std::endl;
	std::cout << "hit points   : " << clapTrap2.getHitPoints() << std::endl;
	std::cout << "------------------" << std::endl;

	clapTrap2.attack("enemy");

	while (clapTrap2.getEnergyPoints() > 0)
		clapTrap2.beRepaired(1);

	clapTrap2.beRepaired(1);

	return (0);
}
