/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 00:04:13 by ahocine           #+#    #+#             */
/*   Updated: 2022/11/17 00:05:05 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.Class.hpp"

Harl::Harl(void)
{
	return ;
}

Harl::~Harl(void)
{
	return ;
}

void	Harl::_warning(void)
{
	std::cout << "[WARNING]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon "
		<< "for free. I’ve been coming foryears whereas you "
		<< "started working here since last month." << std::endl;
}

void	Harl::_debug(void)
{
	std::cout << "[DEBUG]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double "
		<< "-cheese-triple-pickle-special ketchup burger. I "
		<< "really do!" << std::endl;
}

void	Harl::_error(void)
{
	std::cout << "[ERROR]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the "
		<< "manager now." << std::endl;
}

void	Harl::_info(void)
{
	std::cout << "[INFO]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more "
	<< "money. You didn’t put enough bacon in my burger! "
	<< "If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::complain(std::string level)
{
	void		(Harl::*f[4])(void) = {&Harl::_warning, &Harl::_debug, \
					&Harl::_error, &Harl::_info};
	const std::string	levels[4] = {"warning", "debug", "error", "info"};

	int	i;
	for (i = 0 ; i < 4 ; i++)
	{
		if (level == levels[i])
			break;
	}
	switch (i)
	{
	case 0:
		(this->*f[0])();

	case 1:
		(this->*f[1])();

	case 2:
		(this->*f[2])();

	case 3:
		(this->*f[3])();
		break;
	
	default:
		std::cout << "[Probably complaining about insignicant problems]" << std::endl;
	}
}
