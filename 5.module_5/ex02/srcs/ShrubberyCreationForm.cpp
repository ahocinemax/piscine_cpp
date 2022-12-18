/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 19:28:17 by ahocine           #+#    #+#             */
/*   Updated: 2022/12/13 19:28:18 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ShrubberyCreationForm.Class.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("ShrubberyCreationForm", 25, 5), name(target)
{
	std::cout << name << " called full constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &Copy) : Form(Copy)
{
	if (this != &Copy)
		*this = Copy;
	std::cout << Copy.name << " called copy constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(void) : Form("ShrubberyCreationForm", 25, 5), name("NO_NAME")
{
	std::cout << name << " called default constructor" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << name << " called destructor" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
	if (this != &rhs)
	{
		this->Form::operator=(rhs);
		name = rhs.name;
	}
	std::cout << name << " called copy assignement operator" << std::endl;
	return (*this);
}

void	ShrubberyCreationForm::action(const Bureaucrat &manager) const
{
	this->Form::execute(manager);
	std::cout << this->name << " have been pardoned by Zafod Beeblebrox" << std::endl;
}
