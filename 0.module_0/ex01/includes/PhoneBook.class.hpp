/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 22:12:13 by ahocine           #+#    #+#             */
/*   Updated: 2022/10/23 22:13:11 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP
# include "Contact.class.hpp"

void	ft_getline(std::string &input, std::string message, bool command);

class PhoneBook
{
	private:
		Contact	contact[8];

	public:
		std::string ft_cut(std::string str);
		int			ft_check_input(std::string input);
		void		ft_search(void);
		void		ft_show(void);
		void		ft_add(void);

		int			contact_index;
		int			contact_nb;
};

#endif
