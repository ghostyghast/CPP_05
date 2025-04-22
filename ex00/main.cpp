/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 20:05:10 by amaligno          #+#    #+#             */
/*   Updated: 2025/04/22 19:11:28 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int	main(void)
{
std::cout << "------Test1------\n";
	try
	{
		Bureaucrat	guy("guy", 500);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bureaucrat	guy("guy", -10);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

std::cout << "------Test2------\n";

	Bureaucrat	bob;
	Bureaucrat	guy("guy", 50);

	std::cout << bob << '\n';
	try
	{
		bob.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	for (int i = 0; i <= 150; i++)
	{
		try
		{
			bob.incrementGrade();
			std::cout << bob << '\n';
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	
}