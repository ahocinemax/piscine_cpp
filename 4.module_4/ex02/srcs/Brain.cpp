/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 04:20:39 by ahocine           #+#    #+#             */
/*   Updated: 2022/11/24 04:20:42 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/Brain.Class.hpp"

Brain &Brain::operator=(const Brain &rhs)
{
	std::cout << "Brain assignation operator called" << std::endl;
	if (&rhs == this)
		return (*this);
	for (int i = 0 ; i < 100 ; i++)
	{
		ideas[i] = rhs.ideas[i];
	}
	return (*this);
}

Brain::Brain(const Brain &Copy)
{
	std::cout << "Brain copy constructor called" << std::endl;
	if (this != &Copy)
		*this = Copy;
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain(void)
{
	std::cout << "Brain default constructor called" << std::endl;
}

const std::string	&Brain::getIdea(int id) const
{
	return (ideas[id]);
}

void	Brain::setIdeas(int id, std::string idea)
{
	if (id >= 0 && id < 100)
		ideas[id] = idea;
	else
		std::cout << "Please enter a number between 0 - 99" << std::endl;
}

