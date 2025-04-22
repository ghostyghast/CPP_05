/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 18:21:40 by amaligno          #+#    #+#             */
/*   Updated: 2025/04/22 21:04:54 by amaligno         ###   ########.fr       */
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

typedef struct s_form_pair
{
	const char				*name;
	AForm *(*create)(std::string);
}	t_form_pair;

template <typename T> static AForm *newForm(std::string target)
{
	return (new T(target));
}

AForm	*Intern::makeForm(std::string name, std::string target)
{
	t_form_pair	forms[3] = {
	{"shrubbery creation", newForm<ShrubberyCreationForm>},
	{"robotomy request", newForm<RobotomyRequestForm>},
	{"presidential pardon", newForm<PresidentialPardonForm>},
	};

	for (int i = 0; i < 3; i++)
		if (forms[i].name == name)
			return forms[i].create(target);
	std::cout << name << " form does not exist\n";
	return NULL;
}