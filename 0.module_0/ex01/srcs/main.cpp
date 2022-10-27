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

#include "../includes/PhoneBook.class.hpp"

void    ft_getline(std::string &input, bool line)
{
    if (!std::getline(std::cin, input));
        exit(0);
    if (input.empty() == true)
    {
        std::cout << "Empty line, please enter a value:" << std::endl;
        ft_getline(input, true);
    }
}