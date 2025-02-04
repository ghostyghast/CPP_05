/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 20:05:10 by amaligno          #+#    #+#             */
/*   Updated: 2025/02/04 19:41:02 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.cpp"
#include <iostream>

using	std::cout;

int	main(void)
{
	Intern		unpaid;
	Bureaucrat	bob("bob", 1);
	Bureaucrat	gerald("gerald", 140);
	AForm		*treeform = unpaid.makeForm("shrubbery creation", "42");
	AForm		*robotizer = unpaid.makeForm("robotomy request", "bob");
	AForm		*president = unpaid.makeForm("presidential pardon", "bobby");
	
	cout << "------Test1------" << '\n';
	try
	{
		gerald.executeForm(*treeform);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	cout << "------Test2------" << '\n';
	cout << gerald << '\n';
	try
	{
		gerald.signForm(*treeform);
		gerald.executeForm(*treeform);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	cout << "------Test3------" << '\n';
	for (int i = 0; i < 3; i++)
		gerald.incrementGrade();
	cout << gerald << '\n';
	bob.signForm(*treeform);
	bob.executeForm(*treeform);
	cout << "------Test4------" << '\n';
	for (int i = 0; i < 77; i++)
		gerald.incrementGrade();
	cout << gerald << '\n';
	gerald.signForm(*robotizer);
	bob.executeForm(*robotizer);
	bob.signForm(*president);
	bob.executeForm(*president);
}