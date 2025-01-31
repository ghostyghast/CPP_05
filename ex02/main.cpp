/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 20:05:10 by amaligno          #+#    #+#             */
/*   Updated: 2025/01/31 19:28:46 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

using	std::cout;

int	main(void)
{
	Bureaucrat				bob("bob", 1);
	Bureaucrat				gerald("gerald", 140);
	ShrubberyCreationForm	treeform("42");
	RobotomyRequestForm		robotizer("bob");
	PresidentialPardonForm	president("bobby");
	
	cout << "------Test1------" << '\n';
	try
	{
		gerald.executeForm(treeform);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	cout << "------Test2------" << '\n';
	try
	{
		gerald.signForm(treeform);
		gerald.executeForm(treeform);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	cout << "------Test3------" << '\n';
	for (int i = 0; i < 3; i++)
		gerald.incrementGrade();
	cout << gerald << '\n';
	try
	{
		gerald.executeForm(treeform);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}