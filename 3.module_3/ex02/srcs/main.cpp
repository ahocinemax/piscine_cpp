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
#include "../includes/ScavTrap.Class.hpp"
#include "../includes/FragTrap.Class.hpp"

int main(void)
{
	FragTrap fragTrap("FragTrapy");

	std::cout << "------------------" << std::endl;
	std::cout << "initial stats:" << std::endl;
	std::cout << "hit points: " << fragTrap.getHitPoints() << std::endl;
	std::cout << "energy points: " << fragTrap.getEnergyPoints() << std::endl;
	std::cout << "attack damage: " << fragTrap.getAttackDamage() << std::endl;
	std::cout << "------------------" << std::endl;

	fragTrap.attack("enemy");
	
	assert(fragTrap.getHitPoints() == 100);
	assert(fragTrap.getEnergyPoints() == 99);

	fragTrap.takeDamage(5);

	assert(fragTrap.getHitPoints() == 95);
	assert(fragTrap.getEnergyPoints() == 99);

	fragTrap.beRepaired(5);

	assert(fragTrap.getHitPoints() == 100);
	assert(fragTrap.getEnergyPoints() == 98);

	fragTrap.highFiveGuys();

	fragTrap.takeDamage(100);
	assert(fragTrap.getHitPoints() == 0);

	fragTrap.highFiveGuys();
	// ScavTrap is dead now, can't do anything

	return (0);
}