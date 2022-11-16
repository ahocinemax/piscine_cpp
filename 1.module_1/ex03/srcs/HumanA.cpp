/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 23:12:43 by ahocine           #+#    #+#             */
/*   Updated: 2022/11/17 23:12:45 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanA.Class.hpp"

void	HumanA::attack(void) const
{
	std::cout << this->name << " attacks with ";
	std::cout << this->weapon.getType() << std::endl;
}

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon)
{
	std::cout << "HumanA <" << name << "> has been created" << std::endl;
}

HumanA::~HumanA(void)
{
	std::cout << "HumanA <" << name << "> has been destroyed" << std::endl;
}
