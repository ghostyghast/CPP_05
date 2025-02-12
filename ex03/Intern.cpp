/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pringles <pringles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 18:21:40 by amaligno          #+#    #+#             */
/*   Updated: 2025/02/05 20:09:03 by pringles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

#include <iostream>

Intern::Intern()
{
}

Intern::~Intern()
{
}

Intern::Intern(const Intern &copy)
{
	(void)copy;
}

Intern	&Intern::operator=(const Intern &copy)
{
	(void)copy;
	return (*this);
}

template <typename T> static AForm *newForm(std::string target)
{
	return (new T(target));
}

AForm	*Intern::makeForm(std::string name, std::string target)
{
	std::map<std::string, AForm *(*)(std::string)>	forms;
	forms["shrubbery creation"] = newForm<ShrubberyCreationForm>;
	forms["robotomy request"] = newForm<RobotomyRequestForm>;
	forms["presidential pardon"] = newForm<PresidentialPardonForm>;
	try
	{
		return (forms.at(name)(target));
	}
	catch (const std::exception &e)
	{
		std::cerr << name <<" form does not exist\n";
		return (NULL);
	}
}