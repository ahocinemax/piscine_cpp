/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 16:45:47 by ahocine           #+#    #+#             */
/*   Updated: 2022/10/23 17:57:05 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.Class.hpp"

ClapTrap::ClapTrap(const ClapTrap &Copy)
{
    *this = Copy;
    std::cout << this->name << " (bis) called copy constructor" << std::endl;
    return ;
}

ClapTrap::ClapTrap(std::string name)
{
    this->name = name;
    std::cout << this->name << " called constructor" << std::endl;
    return ;
}

ClapTrap::~ClapTrap(void)
{
    std::cout << this->name << " called destructor" << std::endl;
    return ;
}

ClapTrap::ClapTrap(void)
{
    this->name = "ClapTrap";
    std::cout << this->name << " called default constructor" << std::endl;
    return ;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs)
{
    std::cout << "ClapTrap assignation operator called" << std::endl;
    if (this == &rhs)
        return (*this);
    this->name = rhs.getName();
    this->hitPoints = rhs.getHitPoints();
    this->energyPoints = rhs.getEnergyPoints();
    this->attackDamage = rhs.getAttackDamage();
    return (*this);
}

void    ClapTrap::attack(const std::string &target)
{
    if (this->energyPoints <= 0)
    {
        std::cout << "No more energy points for " << this->name << std::endl;
        return ;
    }
    if (this->hitPoints <= 0)
    {
        std::cout << "Not enough hit points to attack " << target << std::endl;
        return ;
    }
    std::cout << this->name << " attacks " << target << " causing ";
    std::cout << this->hitPoints << " damage(s)." << std::endl;
    this->energyPoints--;
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << "ClapTrap " << this->name << " takes " << amount;
    std::cout << " damages." << std::endl;
    if (this->hitPoints < amount)
        this->hitPoints = 0;
    else
        this->hitPoints -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
    if (this->energyPoints <= 0)
    {
        std::cout << this->name << " have no more energy points." << std::endl;
        return ;
    }
    if (this->hitPoints <= 0)
    {
        std::cout << "Not enough hit points to attack." << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << this->name << " heals by ";
    std::cout << amount << " points." << std::endl;
    this->hitPoints += amount;
    this->energyPoints--;
}

unsigned int    ClapTrap::getEnergyPoints(void) const
{
    return (this->energyPoints);
}

unsigned int    ClapTrap::getAttackDamage(void) const
{
    return (this->attackDamage);
}

unsigned int    ClapTrap::getHitPoints(void) const
{
    return (this->hitPoints);
}

std::string	    ClapTrap::getName(void) const
{
    return (this->name);
}
