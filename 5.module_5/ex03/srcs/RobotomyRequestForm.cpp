/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 19:38:17 by ahocine           #+#    #+#             */
/*   Updated: 2022/12/13 19:38:18 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RobotomyRequestForm.Class.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("RobotomyRequestForm", 25, 5), name(target)
{
	std::cout << name << " called RRF full constructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &Copy) : Form(Copy)
{
	if (this != &Copy)
		*this = Copy;
	std::cout << Copy.name << " called RRF copy constructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(void) : Form("RobotomyRequestForm", 25, 5), name("NO_NAME")
{
	std::cout << name << " called RRF default constructor" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << name << " called RRF destructor" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
	if (this != &rhs)
	{
		this->Form::operator=(rhs);
		name = rhs.name;
	}
	std::cout << name << " called RRF copy assignement operator" << std::endl;
	return (*this);
}

void	RobotomyRequestForm::action(const Bureaucrat &manager) const
{
	this->Form::execute(manager);
	std::cout << "Make some drilling noises" << std::endl;
	if (rand() < RAND_MAX / 2)
		std::cout << this->getName() << " has been robotomized successfully." << std::endl;
	else
		std::cout << "Robotomy on " << this->getName() << "has failed." << std::endl;
}
