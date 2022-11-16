/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 23:12:43 by ahocine           #+#    #+#             */
/*   Updated: 2022/11/17 23:12:45 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanB.Class.hpp"

void	HumanB::attack(void) const
{
    if (this->weapon)
        std::cout << this->name << " attacks with " << this->weapon->getType() << std::endl;
    else
        std::cout << this->name << " do not have weapon." << std::endl;
}

void    HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
}

HumanB::HumanB(std::string name) : name(name)
{
    this->weapon = NULL;
    std::cout << "HumanB <" << name << "> has been created" << std::endl;
}

HumanB::~HumanB(void)
{
	std::cout << "HumanB <" << name << "> has been destroyed" << std::endl;
}
