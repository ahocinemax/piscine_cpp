/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.Class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 16:45:47 by ahocine           #+#    #+#             */
/*   Updated: 2022/10/23 17:57:05 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_CLASS_HPP
# define CLAPTRAP_CLASS_HPP

# include <string>
# include <iostream>

class ClapTrap
{
	protected:
		unsigned int	energyPoints;
		unsigned int	attackDamage;
		unsigned int	hitPoints;
		std::string		name;

	public:
		ClapTrap(const ClapTrap &Copy);
		ClapTrap(std::string name);
		~ClapTrap(void);
		ClapTrap(void);

		ClapTrap &operator=(const ClapTrap &rhs);

		void			attack(const std::string &target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);

		unsigned int	getEnergyPoints(void) const;
		unsigned int	getAttackDamage(void) const;
		unsigned int	getHitPoints(void) const;
		std::string		getName(void) const;

		;	
};

#endif
