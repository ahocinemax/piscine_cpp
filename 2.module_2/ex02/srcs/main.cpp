/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 16:45:47 by ahocine           #+#    #+#             */
/*   Updated: 2022/10/23 17:57:05 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.Class.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed const c( Fixed( 5 ) + Fixed( 3.4f ) );

	// std::cout << std::endl << "Pre-incrementation of a: " << std::endl;
	// std::cout << "before: " << a << std::endl;
	++a;
	// std::cout << "after : " << a << std::endl;

	// std::cout << "Post-incrementation of a:" << std::endl;
	// std::cout << "before: " << a << std::endl;
	a++;
	// std::cout << "after : " << a << std::endl << std::endl;

	// std::cout << "Pre-decrementation of a: " << std::endl;
	// std::cout << "before: " << a << std::endl;
	--a;
	// std::cout << "after : " << a << std::endl;

	// std::cout << "Post-decrementation of a: " << std::endl;
	// std::cout << "before: " << a << std::endl;
	a--;
	// std::cout << "after : " << a << std::endl;
	std::cout << "is a > b ? : " << (a > b) << std::endl;
	std::cout << "is a < b ? : " << (a < b) << std::endl;

	std::cout << std::endl;

	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << "b value: " << b << std::endl;
	std::cout << "c value: " << c << std::endl;
	std::cout << ((b != c) ? "true" : "false") << std::endl;

	return 0;
}
