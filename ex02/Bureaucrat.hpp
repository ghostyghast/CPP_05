/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 18:50:47 by amaligno          #+#    #+#             */
/*   Updated: 2025/02/04 17:30:44 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Bureaucrat_HPP
# define Bureaucrat_HPP

# include <exception>
# include <string>

class	AForm;

class Bureaucrat
{
	public:
	//Constructors
		Bureaucrat();
		Bureaucrat(std::string name, short grade);
		Bureaucrat(const Bureaucrat &copy);
	//Destructor
		~Bureaucrat();
	//Getters	
		const std::string	&getName(void) const;	
		const short			&getGrade(void) const;
	//Methods
		void				signForm(AForm &form) const;
		void				executeForm(AForm const &form) const;
		void				incrementGrade(void);
		void				decrementGrade(void);
	//Operator Overloads
		Bureaucrat			&operator=(const Bureaucrat &copy);

	//Exceptions
		class GradeTooHighException : public std::exception
		{
			public:
				const char	*what() const throw();	
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char	*what() const throw();	
		};
		
	private:
		const std::string	_name;
		short				_grade;
};

# include "AForm.hpp"

std::ostream	&operator<<(std::ostream &stream, const Bureaucrat &b);

#endif