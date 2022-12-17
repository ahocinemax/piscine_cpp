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
#include "../includes/Form.Class.hpp"

Bureaucrat::Bureaucrat(std::string name, int range) : name(name), range(range)
{
	if (range < 1)
		throw Bureaucrat::GradeTooHighException();
	if (range > 150)
		throw Bureaucrat::GradeTooLowException();
	std::cout << this->name << " called Bureaucrat full constructor" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : name(src.getName()), range(src.getGrade())
{
	std::cout << this->name << " called Bureaucrat copy constructor" << std::endl;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << this->name << " called Bureaucrat destructor" << std::endl;
}

Bureaucrat::Bureaucrat(void) : name("Basic bureaucrat"), range(150)
{
	std::cout << "Basic bureaucrat called Bureaucrat default constructor" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs)
{
	if (this == &rhs)
		return (*this);
	range = rhs.getGrade();
	std::cout << this->name << " Bureaucrat assignation operator called" << std::endl;
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

void	Bureaucrat::increment(void)
{
	if (this->getGrade() < 2)
		range -= 1;
	else
		throw GradeTooHighException();
}

void	Bureaucrat::decrement(void)
{
	if (this->getGrade() > 149)
		range += 1;
	else
		throw GradeTooLowException();
}

void	Bureaucrat::signForm(Form &form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << *this << " signed " << form << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << *this << " can't sign " << form << " because " << e.what() << std::endl;
	}
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
	return ("Grade cannot be better than 1.");
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
	return ("Grade cannot be worst than 150.");
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &rhs)
{
	out << rhs.getName() << " (grade " << rhs.getGrade() << ") ";
	return (out);
}