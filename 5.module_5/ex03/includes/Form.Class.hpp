/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.Class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 22:58:17 by ahocine           #+#    #+#             */
/*   Updated: 2022/11/26 22:58:18 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_CLASS_HPP
# define FORM_CLASS_HPP

# include <string>
# include <iostream>

class Bureaucrat;

class Form
{
	private:
		bool		isSigned = false;
		int			gradeExec;
		int			gradeSign;
		std::string	name;

	public:
		// Constructors & Destructor
		Form(const std::string &name);
		Form(const std::string &name, const int gradeSign, const int gradeExec);
		Form(const Form &src);
		~Form(void);
		Form(void);
		
		// Assignement operator
		Form &operator=(const Form &rhs);

		// Getters
		const bool			getIsSigned(void) const;
		const int			getGradeSign(void) const;
		const int			getGradeExec(void) const;
		const std::string	&getName(void) const;

		// Member functions
		void			beSigned(const Bureaucrat &manager);
		void			execute(const Bureaucrat &executor) const;
		virtual void	action(const Bureaucrat &manager) const = 0;

		// Exceptions
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char	*what() const throw()
				{
					return ("grade is too high");
				}
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char	*what() const throw()
				{
					return ("grade is too low");
				}
		};

		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char	*what() const throw()
				{
					return ("form is not signed");
				}
		};

		class IsAlreadySignedException : public std::exception
		{
			public:
				virtual const char	*what() const throw()
				{
					return ("Form is already signed");
				}
		};
};

std::ostream &operator<<(std::ostream &out, Form const &rhs);

#endif
