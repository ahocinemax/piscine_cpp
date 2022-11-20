/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 16:45:47 by ahocine           #+#    #+#             */
/*   Updated: 2022/10/23 17:57:05 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.Class.hpp"

ScavTrap::ScavTrap(const ScavTrap &Copy)
{
	*this = Copy;
	std::cout << this->name << " (bis) called ScavTrap copy constructor" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
	this->energyPoints = 50;
	this->attackDamage = 20;
	this->hitPoints = 100;
	this->name = name;
	std::cout << this->name << " called ScavTrap constructor" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << this->name << " called ScavTrap destructor" << std::endl;
}

ScavTrap::ScavTrap(void)
{
	this->name = "ScavTrap";
	this->energyPoints = 50;
	this->attackDamage = 20;
	this->hitPoints = 100;
	std::cout << "ScavTrap called default constructor" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &rhs)
{
	ClapTrap::operator=(rhs);
	std::cout << "ScavTrap assignation operator called" << std::endl;
	return (*this);
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->energyPoints <= 0)
	{
		std::cout << "No more ScavTrap's energy points for " << this->name << std::endl;
		return ;
	}
	if (this->hitPoints <= 0)
	{
		std::cout << "Not enough ScavTrap's hit points to attack " << target << std::endl;
		return ;
	}
	std::cout << this->name << " attacks " << target << " causing ";
	std::cout << this->hitPoints << " damage(s)." << std::endl;
	this->energyPoints--;
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->name << " has entered in Gate keeper mode" << std::endl;
}
