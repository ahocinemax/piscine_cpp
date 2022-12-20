/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.Class.hpp                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 22:58:17 by ahocine           #+#    #+#             */
/*   Updated: 2022/11/26 22:58:18 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_CLASS_HPP
# define SHRUBBERYCREATIONFORM_CLASS_HPP

# include "Form.Class.hpp"

class ShrubberyCreationForm : public Form
{
    private:
        std::string name;
    
    public:
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm &Copy);
        ShrubberyCreationForm(void);
        virtual ~ShrubberyCreationForm(void);

        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);

        void    action(const Bureaucrat &manager) const;
};

#endif