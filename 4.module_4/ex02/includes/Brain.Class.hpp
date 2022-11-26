/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.Class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 04:21:00 by ahocine           #+#    #+#             */
/*   Updated: 2022/11/24 04:21:02 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_CLASS_HPP
# define BRAIN_CLASS_HPP

# include "Animal.Class.hpp"

class Brain
{
	private:
		std::string ideas[100];

	public:
		Brain &operator=(const Brain &rhs);
		Brain(const Brain &Copy);
		~Brain(void);
		Brain(void);

		const std::string	&getIdea(int id) const;
		void	setIdeas(int id, std::string idea);
};

#endif
