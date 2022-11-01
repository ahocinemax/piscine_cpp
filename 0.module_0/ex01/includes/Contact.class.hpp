/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 22:12:13 by ahocine           #+#    #+#             */
/*   Updated: 2022/10/23 22:13:11 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <string>
#include <iomanip>
#include <sstream>

class Contact
{
	private:
		std::string	DarkestSecret;
		std::string	PhoneNumber;
		std::string	FirstName;
		std::string	LastName;
		std::string	NickName;

	public:
		void		SetElement(std::string value, int element);
		std::string	GetElement(int element) const;
		void		show(void);
};

#endif