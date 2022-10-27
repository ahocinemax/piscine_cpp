/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 22:12:13 by ahocine           #+#    #+#             */
/*   Updated: 2022/10/23 22:13:11 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Contact.class.hpp"

std::string	Contact::GetElement(int element) const
{
	switch (element)
	{
		case 0:
			return (this->DarkestSecret);
			break;
		case 1:
			return (this->PhoneNumber);
			break;
		case 2:
			return (this->FirstName);
			break;
		case 3:
			return (this->LastName);
			break;
		case 4:
			return (this->NickName);
			break;
		default:
			return ((std::string)0);
	}
}

void	Contact::SetElement(std::string value, int element)
{
	switch (element)
	{
		case 0:
			this->DarkestSecret = value;
			break;
		case 1:
			this->PhoneNumber = value;
			break;
		case 2:
			this->FirstName = value;
			break;
		case 3:
			this->LastName = value;
			break;
		case 4:
			this->NickName = value;
		default:
			break;
	}
}

void	show(void)
{
	;
}
