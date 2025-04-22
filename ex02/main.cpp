/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 20:05:10 by amaligno          #+#    #+#             */
/*   Updated: 2025/04/22 20:29:25 by amaligno         ###   ########.fr       */
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
	PresidentialPardonForm	president("criminal");
	
	cout << "------Test1------" << '\n';
	try
	{
		gerald.executeForm(treeform);
	}
	catch(const std::exception& e)
	{
		 cout << e.what() << '\n';
	}
	cout << "------Test2------" << '\n';
	cout << gerald << '\n';
	try
	{
		gerald.signForm(treeform);
		gerald.executeForm(treeform);
	}
	catch(const std::exception& e)
	{
		 cout << e.what() << '\n';
	}
	cout << "------Test3------" << '\n';
	for (int i = 0; i < 3; i++)
		gerald.incrementGrade();
	cout << gerald << '\n';
	bob.signForm(treeform);
	bob.executeForm(treeform);
	cout << "------Test4------" << '\n';
	for (int i = 0; i < 77; i++)
		gerald.incrementGrade();
	cout << gerald << '\n';
	gerald.signForm(robotizer);
	bob.executeForm(robotizer);
	bob.signForm(president);
	bob.executeForm(president);
}