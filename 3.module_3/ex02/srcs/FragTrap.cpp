/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 16:45:47 by ahocine           #+#    #+#             */
/*   Updated: 2022/10/23 17:57:05 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.Class.hpp"

FragTrap::FragTrap(const FragTrap &Copy)
{
	*this = Copy;
	std::cout << this->name << " (bis) called FragTrap copy constructor" << std::endl;
	return ;
}

FragTrap::FragTrap(std::string name)
{
	this->name = name;
	this->attackDamage = 30;
	this->energyPoints = 100;
	this->hitPoints = 100;
	std::cout << this->name << " called FragTrap constructor" << std::endl;
	return ;
}

FragTrap::~FragTrap(void)
{
	std::cout << this->name << " called FragTrap destructor" << std::endl;
	return ;
}

FragTrap::FragTrap(void)
{
	this->name = "FragTrap";
	this->attackDamage = 30;
	this->energyPoints = 100;
	this->hitPoints = 100;
	std::cout << this->name << " called FragTrap default constructor" << std::endl;
	return ;
}

FragTrap &FragTrap::operator=(const FragTrap &rhs)
{
	std::cout << "FragTrap assignation operator called" << std::endl;
	if (this == &rhs)
		return (*this);
	this->name = rhs.getName();
	this->hitPoints = rhs.getHitPoints();
	this->energyPoints = rhs.getEnergyPoints();
	this->attackDamage = rhs.getAttackDamage();
	return (*this);
}

void    FragTrap::attack(const std::string &target)
{
	if (this->energyPoints <= 0)
	{
		std::cout << "No more FragTrap's energy points for " << this->name << std::endl;
		return ;
	}
	if (this->hitPoints <= 0)
	{
		std::cout << "Not enough FragTrap's hit points to attack " << target << std::endl;
		return ;
	}
	std::cout << this->name << " attacks " << target << " causing ";
	std::cout << this->hitPoints << " damage(s)." << std::endl;
	this->energyPoints--;
}

void    FragTrap::highFiveGuys(void)
{
    if (this->hitPoints <= 0 || this->energyPoints <= 0)
        std::cout << "FragTrap " << this->name << " doesn't have enough energy." << std::endl;
    else
        std::cout << "FragTrap " << this->name << " gives a high five." << std::endl;
}