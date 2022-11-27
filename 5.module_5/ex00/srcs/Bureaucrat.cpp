/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 22:58:30 by ahocine           #+#    #+#             */
/*   Updated: 2022/11/26 22:58:31 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.Class.hpp"

Bureaucrat::Bureaucrat(std::string name, int range) : name(name), range(range)
{
	if (range < 1)
		throw Bureaucrat::GradeTooHighException();
	if (range > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : name(src.getName()), range(src.getGrade())
{
	;
}

Bureaucrat::~Bureaucrat(void)
{
	;
}

Bureaucrat::Bureaucrat(void) : name("Basic bureaucrat"), range(150)
{
	;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs)
{
	if (this == &rhs)
		return (*this);
	range = rhs.getGrade();
	return (*this);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->range);
}

const std::string	&Bureaucrat::getName(void) const
{
	return (this->name);
}

void	Bureaucrat::toTheMoon(void)
{
	if (this->getGrade() < 2)
		range -= 1;
	else
		throw GradeTooHighException();
}

void	Bureaucrat::toTheFomo(void)
{
	if (this->getGrade() > 149)
		range += 1;
	else
		throw GradeTooLowException();

}

const char	*Bureaucrat::GradeTooHighException::what() const
{
	std::cout << "Grade cannot be better than 1." << std::endl;
}

const char	*Bureaucrat::GradeTooLowException::what() const
{
	std::cout << "Grade cannot be worst than 150." << std::endl;
}
