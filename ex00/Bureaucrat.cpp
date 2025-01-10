/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 18:50:50 by amaligno          #+#    #+#             */
/*   Updated: 2025/01/10 20:23:52 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat() :  _name("Cog"), _grade(150)
{
}

Bureaucrat::Bureaucrat(std::string name, short grade) :  _name(name), _grade(grade)
{
}

Bureaucrat::Bureaucrat(Bureaucrat &copy) : _name(copy.getName()), _grade(copy.getGrade())
{
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat &copy)
{
	this->_grade = copy.getGrade();
	return (*this);
}

std::ostream	&Bureaucrat::operator<<(std::ostream &stream, const Bureaucrat &b)
{
	stream << b.getName() << ", bureaucrat grade " << b.getGrade();
	return (stream);
}

const std::string	&Bureaucrat::getName(void) const
{
	return(this->_name);
}	

const short	&Bureaucrat::getGrade(void) const
{
	return(this->_grade);
}	

void		Bureaucrat::incrementGrade(void)
{
	this->_grade--;
	if (this->_grade < 1)
		throw GradeTooHighException();
}

void		Bureaucrat::decrementGrade(void)
{
	this->_grade++;
	if (this->_grade > 150)
		throw GradeTooLowException();
}

const char		*Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high!");
}

const char		*Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low!");
}