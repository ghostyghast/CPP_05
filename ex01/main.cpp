/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 20:05:10 by amaligno          #+#    #+#             */
/*   Updated: 2025/01/24 19:16:04 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

using	std::cout;

int	main(void)
{
	Bureaucrat	guy("guy", 50);
	Form		form("Alive form", 150, 150);
	cout << "------Test1------" << '\n';
	cout << guy << '\n';
	cout << form << '\n';
	guy.signForm(form);
	cout << form << '\n';

	cout << "------Test2------" << '\n';
	Bureaucrat	lameguy("lame guy", 150);
	Form		coolform("Cool form", 1, 1);
	cout << lameguy << '\n';
	cout << coolform << '\n';
	lameguy.signForm(coolform);
	cout << coolform << '\n';

	cout << "------Test3------" << '\n';
	try
	{
		Form	test("testform", 0, 1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Form	test("testform", 151, 1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}