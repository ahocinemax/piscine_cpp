/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 22:58:30 by ahocine           #+#    #+#             */
/*   Updated: 2022/11/26 22:58:31 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.Class.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	std::cout << this->name << " called Bureaucrat full constructor" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &Copy)
{
	if (this != &Copy)
		*this = Copy;
	std::cout << this->name << " called Bureaucrat copy constructor graded " << this->grade << std::endl;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << this->name << " called Bureaucrat destructor" << std::endl;
}

Bureaucrat::Bureaucrat(void) : name("Basic bureaucrat"), grade(150)
{
	std::cout << "Basic bureaucrat called Bureaucrat default constructor" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs)
{
	if (this == &rhs)
		return (*this);
	grade = rhs.getGrade();
	std::cout << this->name << " Bureaucrat assignation operator called" << std::endl;
	return (*this);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->grade);
}

const std::string	&Bureaucrat::getName(void) const
{
	return (this->name);
}

void	Bureaucrat::increment(void)
{
	if (this->getGrade() > 1)
		grade -= 1;
	else
		throw GradeTooHighException();
}

void	Bureaucrat::decrement(void)
{
	if (this->getGrade() < 150)
		grade += 1;
	else
		throw GradeTooLowException();

}

Bureaucrat::GradeTooHighException::GradeTooHighException(const GradeTooHighException &Copy)
{
	*this = Copy;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(void)
{
	return ;
}

Bureaucrat::GradeTooHighException::~GradeTooHighException(void) throw()
{
	return ;
}

Bureaucrat::GradeTooHighException
&Bureaucrat::GradeTooHighException::operator=(const GradeTooHighException &rhs)
{
	static_cast <void> (rhs);
	return (*this);
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("\e[31mGrade cannot be better than 1.\e[0m");
}

Bureaucrat::GradeTooLowException::GradeTooLowException(const GradeTooLowException &Copy)
{
	*this = Copy;
}

Bureaucrat::GradeTooLowException::GradeTooLowException(void)
{
	return ;
}

Bureaucrat::GradeTooLowException::~GradeTooLowException(void) throw()
{
	return ;
}

Bureaucrat::GradeTooLowException
&Bureaucrat::GradeTooLowException::operator=(const GradeTooLowException &rhs)
{
	static_cast <void> (rhs);
	return (*this);
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("\e[31mGrade cannot be worst than 150.\e[0m");
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &rhs)
{
	out << rhs.getName() << "graded " << rhs.getGrade() << std::endl;
	return (out);
}