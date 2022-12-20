/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 22:54:07 by ahocine           #+#    #+#             */
/*   Updated: 2022/11/26 22:54:08 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PresidentialPardonForm.Class.hpp"
#include "../includes/ShrubberyCreationForm.Class.hpp"
#include "../includes/RobotomyRequestForm.Class.hpp"
#include "../includes/Intern.Class.hpp"
#include "../includes/Form.Class.hpp"

Intern::Intern(void)
{
	std::cout << "Intern full constructor called." << std::endl;
}

Intern::~Intern(void)
{
	std::cout << "Intern destructor called." << std::endl;
}

Form	*Intern::makeForm(const std::string &form, const std::string &target) const
{
	std::string nameList[3] = 
	{
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	Form	*tmp = NULL;
	int		i = 0;

	while (i < 3 && form != nameList[i])
		i++;
	switch (i)
	{
		case 0:
			tmp = new ShrubberyCreationForm(target);
			break;
		case 1:
			tmp = new RobotomyRequestForm(target);
			break;
		case 2:
			tmp = new PresidentialPardonForm(target);
			break;
		default:
			throw Intern::InvalidFormException();
	}
	std::cout << "Intern creates " << form << std::endl;
	return tmp;
}

const char	*Intern::InvalidFormException::what() const throw()
{
	return ("\e[31mForm does not exist.\e[0m");
}
