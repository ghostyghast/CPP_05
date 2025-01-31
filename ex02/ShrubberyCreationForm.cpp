/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 19:11:22 by amaligno          #+#    #+#             */
/*   Updated: 2025/01/31 17:37:20 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

#include <iostream>
#include <fstream>

using	std::string;
using	std::cout;
using	std::ofstream;

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation Form", 145, 137), _target("None")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(string target) : AForm("Shrubbery Creation Form", 145, 137), _target(target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy)
{
	*this = copy;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
	AForm::operator=(copy);
	this->_target = copy._target;
	return (*this);
}

void	ShrubberyCreationForm::performExecute() const
{
	ofstream	file((this->_target + "_shrubbery").c_str());
	file << "          / / /\n\
                   /        /  /     //    / \n\
                /                 /         /  / \n\
                                /\n\
                               /                //\n\
               /          /            /              /\n\
               /            '/,        /               /\n\
               /              'b      *\n\
                /              '$    //                //\n\
               /    /           $:   /:               /\n\
             //      /  //      */  @):        /   / /\n\
                          /     :@,@):   ,/**:'   /\n\
              /      /,         :@@*: //**'      /   /\n\
                       '/o/    /:(@'/@*\"'  /\n\
               /  /       'bq,/ /:,@@*'   ,*      /  /\n\
                          ,p$q8,:@)'  /p*'      /\n\
                   /     '  / '@@Pp@@*'    /  /\n\
                    /  / / /    Y7'.'     /  /\n\
                              :@):.\n\
                             .:@:'.\n\
                           .::(@:.      \n";
	file.close();
}