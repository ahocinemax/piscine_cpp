/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.Class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 23:12:43 by ahocine           #+#    #+#             */
/*   Updated: 2022/11/17 23:12:45 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_CLASS_HPP
# define WEAPON_CLASS_HPP

# include <string>
# include <iostream>

class Weapon
{
	private:
		std::string		type;

	public:
		Weapon(std::string type);
		~Weapon(void);
		const std::string	&getType(void) const;
		void				setType(std::string type);
};

#endif