/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 22:39:26 by ahocine           #+#    #+#             */
/*   Updated: 2022/11/24 22:39:28 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.Class.hpp"

int main(void)
{
    std::cout << "MODULE 1 - EX01" << std::endl << std::endl;

    std::cout << "New horde of Zombies incomming..." << std::endl;
    Zombie  *horde = zombieHorde(10, "Jacques");
    std::cout << std::endl;
    for (int i = 0 ; i < 10 ; i++)
    {
        horde[i].announce();
        std::cout << std::endl;
    }
    std::cout << std::endl;
    delete [] horde;
    return (0);
}
