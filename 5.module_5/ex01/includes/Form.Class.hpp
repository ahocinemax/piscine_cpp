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
		void	beSigned(const Bureaucrat &Manager);

		// Exceptions
		class GradeTooHighException : public std::exception
		{
			public:
				const char	*what() const throw()
				{
					return ("\e[31mgrade is too high\e[0m");
				}
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char	*what() const throw()
				{
					return ("\e[31mgrade is too low\e[0m");
				}
		};

		class IsAlreadySignedException : public std::exception
		{
			public:
				const char	*what() const throw()
				{
					return ("\e[31mForm is already signed\e[0m");
				}
		};
};

std::ostream &operator<<(std::ostream &out, Form const &rhs);

#endif
