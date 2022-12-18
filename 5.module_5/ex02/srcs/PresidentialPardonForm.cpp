/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 22:58:17 by ahocine           #+#    #+#             */
/*   Updated: 2022/11/26 22:58:18 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PresidentialPardonForm.Class.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("PresidentialPardonForm", 25, 5), name(target)
{
	std::cout << name << " called full constructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &Copy) : Form(Copy)
{
	if (this != &Copy)
		*this = Copy;
	std::cout << Copy.name << " called copy constructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(void) : Form("PresidentialPardonForm", 25, 5), name("NO_NAME")
{
	std::cout << name << " called default constructor" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << name << " called destructor" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
	if (this != &rhs)
	{
		this->Form::operator=(rhs);
		name = rhs.name;
	}
	std::cout << name << " called copy assignement operator" << std::endl;
	return (*this);
}

void	PresidentialPardonForm::action(const Bureaucrat &manager) const
{
	this->Form::execute(manager);
	std::cout << this->getName() << " have been pardoned by Zafod Beeblebrox" << std::endl;
}
