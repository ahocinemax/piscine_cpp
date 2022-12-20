/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@stduent.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:45:20 by ahocine           #+#    #+#             */
/*   Updated: 2022/12/20 16:45:37 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Base.Class.hpp"
#include "../includes/A.Class.hpp"
#include "../includes/B.Class.hpp"
#include "../includes/C.Class.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

Base *generate(void)
{
    std::srand(std::time(NULL));
    int i = rand() % 3;
    switch (i)
    {
        case 0:
            std::cout << "A generated" << std::endl;
            return (new A);
            break;
        case 1:
            std::cout << "B generated" << std::endl;
            return (new B);
            break;
        case 2:
            std::cout << "C generated" << std::endl;
            return (new C);
            break;
        
        default:
            return (new C)
    }
    return (NULL);
}

int main(void)
{

}
