/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 20:05:10 by amaligno          #+#    #+#             */
/*   Updated: 2025/04/22 21:07:26 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

using	std::cout;

int	main(void)
{
	cout << "------Test1------" << '\n';
	try
	{
		Form		form("Alive form", 150, 151);
	}
	catch(const std::exception& e)
	{
		cout << e.what() << '\n';
	}
	try
	{
		Form		form("Alive form", 151, 150);
	}
	catch(const std::exception& e)
	{
		cout << e.what() << '\n';
	}
	try
	{
		Form		form("Alive form", 150, 0);
	}
	catch(const std::exception& e)
	{
		cout << e.what() << '\n';
	}
	try
	{
		Form		form("Alive form", 0, 150);
	}
	catch(const std::exception& e)
	{
		cout << e.what() << '\n';
	}

	cout << "------Test2------" << '\n';
	Bureaucrat	guy("guy", 50);
	Form		form("Alive form", 150, 150);
	cout << guy << '\n';
	cout << form << '\n';
	guy.signForm(form);
	cout << form << '\n';

	cout << "------Test3------" << '\n';
	Bureaucrat	lameguy("lame guy", 150);
	Form		coolform("Cool form", 1, 1);
	cout << lameguy << '\n';
	cout << coolform << '\n';
	lameguy.signForm(coolform);
	cout << coolform << '\n';
}