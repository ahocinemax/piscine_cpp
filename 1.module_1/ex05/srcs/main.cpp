/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 00:04:13 by ahocine           #+#    #+#             */
/*   Updated: 2022/11/17 00:05:05 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.Class.hpp"

int main(void)
{
    std::string level;
    Harl        harl;

    while (true)
    {
        std::cout << "Enter a message : ";
        std::cin >> level;
        harl.complain(level);
    }
}
