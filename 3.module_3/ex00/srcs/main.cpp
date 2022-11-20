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
	ClapTrap clapTrap("ClapTrapy");

	std::cout << "------------------" << std::endl;
	std::cout << "initial stats:" << std::endl;
	std::cout << "hit points: " << clapTrap.getHitPoints() << std::endl;
	std::cout << "energy points: " << clapTrap.getEnergyPoints() << std::endl;
	std::cout << "attack damage: " << clapTrap.getAttackDamage() << std::endl;
	std::cout << "------------------" << std::endl;

	clapTrap.attack("enemy");
	
	assert(clapTrap.getHitPoints() == 10);
	assert(clapTrap.getEnergyPoints() == 9);

	clapTrap.takeDamage(5);

	assert(clapTrap.getHitPoints() == 5);
	assert(clapTrap.getEnergyPoints() == 9);

	clapTrap.beRepaired(5);

	assert(clapTrap.getHitPoints() == 10);
	assert(clapTrap.getEnergyPoints() == 8);

	clapTrap.takeDamage(20);
	assert(clapTrap.getHitPoints() == 0);

	// ClapTrap is dead now, can't do anything

	clapTrap.attack("enemy2");
	clapTrap.beRepaired(5);

	std::cout << clapTrap.getHitPoints() << std::endl;

	ClapTrap clapTrap2("damian");

	std::cout << "------------------" << std::endl;
	std::cout << "initial stats:" << std::endl;
	std::cout << "hit points: " << clapTrap2.getHitPoints() << std::endl;
	std::cout << "energy points: " << clapTrap2.getEnergyPoints() << std::endl;
	std::cout << "attack damage: " << clapTrap2.getAttackDamage() << std::endl;
	std::cout << "------------------" << std::endl;

	clapTrap2.attack("enemy");

	while (clapTrap2.getEnergyPoints() > 0)
		clapTrap2.beRepaired(1);

	assert(clapTrap2.getEnergyPoints() == 0);

	// shouln't be able to repair anymore
	clapTrap2.beRepaired(1);

	return (0);
}
