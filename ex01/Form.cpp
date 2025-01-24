/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 19:54:54 by amaligno          #+#    #+#             */
/*   Updated: 2025/01/24 19:07:41 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

#include <iostream>

using std::string;
using std::cout;

Form::Form() : _name("Basic Form"), _signed(0), _signGrade(150), _execGrade(150)
{
}

Form::Form(string name, int sign_grade, int exec_grade) : _name(name), _signed(0), _signGrade(sign_grade), _execGrade(exec_grade)
{
	if (sign_grade > 150 || exec_grade > 150)
		throw (GradeTooLowException());
	if (sign_grade < 1 || exec_grade < 1)
		throw (GradeTooHighException());
}

Form::~Form()
{
}

Form::Form(const Form &copy) : _name(copy.getName()), _signed(copy.getSigned()), _signGrade(copy.getSignGrade()), _execGrade(0)
{
}

Form	&Form::operator=(const Form &copy)
{
	this->_signed = copy.getSigned();
	return (*this);
}

void	Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() <= this->_signGrade)
		this->_signed = true;
	else
		throw GradeTooLowException();
}

const std::string	&Form::getName() const
{
	return(this->_name);
}

const bool	&Form::getSigned() const
{
	return(this->_signed);
}

const int	&Form::getSignGrade() const
{
	return(this->_signGrade);
}

const int	&Form::getExecGrade() const
{
	return(this->_execGrade);
}

std::ostream	&operator<<(std::ostream &stream, const Form &f)
{
	cout << "Name: " << f.getName() << ", ";
	cout << "Signed: " << f.getSigned() << ", ";
	cout << "Sign grade: " << f.getSignGrade() << ", ";
	cout << "Exec grade: " << f.getExecGrade();
	return (stream);
}

const char	*Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high!");
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low!");
}