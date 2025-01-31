/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 19:11:22 by amaligno          #+#    #+#             */
/*   Updated: 2025/01/31 17:37:20 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

#include <iostream>
#include <cstdlib>

using	std::string;
using	std::cout;

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request Form", 72, 45), _target("None")
{
}

RobotomyRequestForm::RobotomyRequestForm(string target) : AForm("Robotomy Request Form", 72, 45), _target(target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy)
{
	*this = copy;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
	AForm::operator=(copy);
	this->_target = copy._target;
	return (*this);
}

void	RobotomyRequestForm::performExecute() const
{
	std::srand((unsigned) time(NULL));
	cout << "******Drilling Noises******\n";
	if (rand() % 2)
		cout << this->_target << " has been robotomised\n";
	else
		cout << "robotomy failed\n";
}