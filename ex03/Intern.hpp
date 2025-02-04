/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 18:18:41 by amaligno          #+#    #+#             */
/*   Updated: 2025/02/04 19:31:51 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <string>
#include <map>

class Intern
{
	public:
		Intern();
		~Intern();
		Intern(const Intern &copy);
		Intern &operator=(const Intern &copy);

		AForm	*makeForm(std::string name, std::string target);


	private:
};

#endif