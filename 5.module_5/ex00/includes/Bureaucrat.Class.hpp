/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.Class.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 22:58:17 by ahocine           #+#    #+#             */
/*   Updated: 2022/11/26 22:58:18 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_CLASS_HPP
# define BUREAUCRAT_CLASS_HPP

# include <exception>
# include <iostream>
# include <string>

class Bureaucrat
{
	private:
		int					grade;
		const std::string	name;

	public:
		// Constructors & Destructor
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &src);
		~Bureaucrat(void);
		Bureaucrat(void);
		
		// Assignement operator
		Bureaucrat &operator=(const Bureaucrat &rhs);
		
		// Getters
		const std::string	&getName(void) const;
		int					getGrade(void) const;

		// Member functions
		void				increment(void);
		void				decrement(void);


		// Exceptions
		class GradeTooHighException : public std::exception
		{
			public:
				GradeTooHighException(const GradeTooHighException &Copy);
				GradeTooHighException(void);
				~GradeTooHighException(void) throw();
				GradeTooHighException &operator=(const GradeTooHighException &rhs);
				const virtual char	*what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				GradeTooLowException(const GradeTooLowException &Copy);
				GradeTooLowException(void);
				~GradeTooLowException() throw();
				GradeTooLowException &operator=(const GradeTooLowException &rhs);
				const virtual char	*what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &rhs);

#endif
