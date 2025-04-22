/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 20:05:10 by amaligno          #+#    #+#             */
/*   Updated: 2025/04/22 21:06:41 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

using std::cout;

int	main(void)
{
 cout << "------Test1------\n";
	try
	{
		Bureaucrat	guy("guy", 500);
	}
	catch (std::exception &e)
	{
		 cout << e.what() << '\n';
	}
	try
	{
		Bureaucrat	guy("guy", -10);
	}
	catch (std::exception &e)
	{
		 cout << e.what() << '\n';
	}

 cout << "------Test2------\n";

	Bureaucrat	bob;
	Bureaucrat	guy("guy", 50);

	 cout << bob << '\n';
	try
	{
		bob.decrementGrade();
	}
	catch(const std::exception& e)
	{
		 cout << e.what() << '\n';
	}
	for (int i = 0; i <= 150; i++)
	{
		try
		{
			bob.incrementGrade();
			 cout << bob << '\n';
		}
		catch (const std::exception &e)
		{
			 cout << e.what() << '\n';
		}
	}
	
}