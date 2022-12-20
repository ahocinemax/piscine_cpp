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
#include <fstream>
#include <cstring>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("ShrubberyCreationForm", 145, 137), name(target)
{
	std::cout << name << " called SCF full constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &Copy) : Form(Copy)
{
	if (this != &Copy)
		*this = Copy;
	std::cout << Copy.name << " called SCF copy constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(void) : Form("ShrubberyCreationForm", 145, 137), name("NO_NAME")
{
	std::cout << name << " called SCF default constructor" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << name << " called SCF destructor" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
	if (this != &rhs)
	{
		this->Form::operator=(rhs);
		name = rhs.name;
	}
	std::cout << name << " called SCF copy assignement operator" << std::endl;
	return (*this);
}

void	ShrubberyCreationForm::action(const Bureaucrat &manager) const
{
	this->Form::execute(manager);
	std::ofstream ofs("John_shrubbery");
	if (!ofs.is_open())
		throw std::ofstream::failure(strerror(errno));
	ofs << "──▒▒▒▒▒▒▒▒───▒▒▒▒▒▒▒▒ " << std::endl;
	ofs << "─▒▐▒▐▒▒▒▒▌▒─▒▒▌▒▒▐▒▒▌▒" << std::endl;
	ofs << "──▒▀▄█▒▄▀▒───▒▀▄▒▌▄▀▒ " << std::endl;
	ofs << "─────██─────────██    " << std::endl;
	ofs << "░░░▄▄██▄░░░░░░░▄██▄░░░" << std::endl;
}
