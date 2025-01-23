/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 19:54:54 by amaligno          #+#    #+#             */
/*   Updated: 2025/01/23 20:10:51 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

using std::string;

Form::Form() : _name("Basic Form"), _sign(0), _signGrade(0), _execGrade(0)
{
}

Form::Form(string name, int grade) : _name(name), _sign(0), _signGrade(grade), _execGrade(0)
{
}

Form::~Form()
{
}

Form::Form(const Form &copy) : _name(copy.getName()), _sign(copy.getSign()), _signGrade(copy.getGrade()), _execGrade(0)
{
}

Form	&Form::operator=(const Form &copy)
{
	this->_sign = copy.getSign();
	return (*this);
}

