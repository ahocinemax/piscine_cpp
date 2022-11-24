/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 05:20:54 by ahocine           #+#    #+#             */
/*   Updated: 2022/11/24 05:20:56 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.Class.hpp"

int main(void)
{
    std::cout << "MODULE 1 - EX00" << std::endl << std::endl;

    std::cout << "local zombie : ";
    {
        Zombie local = Zombie("Paul");
        local.announce();
        std::cout << std::endl;
    }
    std::cout << std::endl;

    std::cout << "scope zombie : ";
    {
        Zombie *scope = newZombie("Mike");
        scope->announce();
        std::cout << std::endl;
        delete(scope);
    }
    std::cout << std::endl;

    std::cout << "random zombie : ";
    randomChump("Hugo");
    return (0);
}
