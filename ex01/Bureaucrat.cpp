/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 18:50:50 by amaligno          #+#    #+#             */
/*   Updated: 2025/04/22 19:05:08 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

using	std::cout;

Bureaucrat::Bureaucrat() :  _name("Cog"), _grade(150)
{
}

Bureaucrat::Bureaucrat(std::string name, short grade) :  _name(name), _grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy.getName()), _grade(copy.getGrade())
{
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &copy)
{
	this->_grade = copy.getGrade();
	return (*this);
}

std::ostream	&operator<<(std::ostream &stream, const Bureaucrat &b)
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
	return ("Grade is too high!");
}

const char		*Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too low!");
}

void	Bureaucrat::signForm(Form &form) const
{
	try
	{
		form.beSigned(*this);
	}
	catch(const std::exception& e)
	{
		cout << this->_name << " couldn't sign form because " << e.what() << '\n';
		return ;
	}
	cout << this->_name << " signed " << form.getName() << '\n';
	
}