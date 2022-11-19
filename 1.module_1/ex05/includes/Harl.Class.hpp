/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.Class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 00:04:13 by ahocine           #+#    #+#             */
/*   Updated: 2022/11/17 00:05:05 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_CLASS_HPP
# define HARL_CLASS_HPP

# include <string>
# include <iostream>

class Harl
{
	private:
		void	_warning(void);
		void	_debug(void);
		void	_error(void);
		void	_info(void);

	public:
		Harl(/* args */);
		~Harl();
		void	complain(std::string level);
};

#endif