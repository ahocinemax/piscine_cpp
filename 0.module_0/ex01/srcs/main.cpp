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

#include "../includes/PhoneBook.Class.hpp"

void	ft_getline(std::string &input, std::string message, bool command)
{
    if (command)
		std::cout << "\e[32m" << message << "\e[0m";
	else
		std::cout << "\e[33m" << message << "\e[0m";
	if (!std::getline(std::cin, input))
		exit(0);
	if (input.empty())
	{
		std::cout << "\e[33mEmpty line, please enter a value.\e[0m" << std::endl;
		ft_getline(input, message, true);
	}
}

int	main(int argc, char *argv[])
{
	std::string	input;
	PhoneBook	annuaire;

	if (argc != 1)
		return (std::cout << "Usage : ./PhoneBook" << std::endl, 1);
	(void)argv;
	annuaire.contact_index = 0;
	annuaire.contact_nb = 0;
	std::cout << "Welcome to PhoneBook !" << std::endl;
	std::cout << "Use ADD, SEARCH or EXIT (Only capital letters)." << std::endl;
	while (input != "EXIT")
	{
		ft_getline(input, "Enter a command : ", true);
		if (input == "ADD")
			annuaire.ft_add();
		else if (input == "SEARCH")
			annuaire.ft_search();
		else if (input != "EXIT")
			std::cout << "\e[34mUse ADD, SEARCH or EXIT.\e[0m" << std::endl;
	}
	std::cout << "EXITING..." << std::endl;
	return (0);
}