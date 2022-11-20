/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.Class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 16:45:47 by ahocine           #+#    #+#             */
/*   Updated: 2022/10/23 17:57:05 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_CLASS_HPP
# define FRAGTRAP_CLASS_HPP

# include "ClapTrap.Class.hpp"

class FragTrap : public ClapTrap
{
    public:
        FragTrap(const FragTrap &Copy);
        FragTrap(std::string name);
        ~FragTrap(void);
        FragTrap(void);

		FragTrap &operator=(const FragTrap &rhs);

        void    attack(const std::string &target);
        void    highFiveGuys(void);
};

#endif
