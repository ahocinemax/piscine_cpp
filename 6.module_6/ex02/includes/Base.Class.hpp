/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.Class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@stduent.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:41:06 by ahocine           #+#    #+#             */
/*   Updated: 2022/12/20 16:41:07 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_CLASS_HPP
# define BASE_CLASS_HPP

#include <iostream>

class Base
{
    public:
        virtual ~Base(){std::cout << "Base constructor called" << std::endl;};
};

#endif
