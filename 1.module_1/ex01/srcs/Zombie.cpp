/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 05:21:44 by ahocine           #+#    #+#             */
/*   Updated: 2022/11/24 05:21:45 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.Class.hpp"

Zombie::Zombie(void)
{
	std::cout << "Zombie has been created" << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << "Zombie has been destroyed" << std::endl;;
}

void	Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ...";
}

void	Zombie::setName(std::string name)
{
	this->name = name;
}
