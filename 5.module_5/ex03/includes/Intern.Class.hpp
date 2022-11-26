/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.Class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 22:54:17 by ahocine           #+#    #+#             */
/*   Updated: 2022/11/26 22:54:25 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_CLASS_HPP
# define INTERN_CLASS_HPP

# include <string>
# include <iostream>

class Intern
{
private:
    /* data */
public:
    Intern(std::string form, std::string target);
    ~Intern();
    void    makeForm(void);
};

Intern::Intern(std::string form, std::string target)
{
}

Intern::~Intern()
{
}

#endif
