/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 18:50:47 by amaligno          #+#    #+#             */
/*   Updated: 2025/01/23 19:38:52 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Bureaucrat_HPP
# define Bureaucrat_HPP

#include <exception>
#include <string>

class Bureaucrat
{
	public:
	//Constructors
		Bureaucrat();
		Bureaucrat(std::string name, short grade);
		Bureaucrat(Bureaucrat &copy);
	//Destructor
		~Bureaucrat();
	//Getters	
		const std::string	&getName(void) const;	
		const short			&getGrade(void) const;
	//Methods
		void				incrementGrade(void);
		void				decrementGrade(void);
	//Operator Overloads
		Bureaucrat			&operator=(Bureaucrat &copy);

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

std::ostream	&operator<<(std::ostream &stream, const Bureaucrat &b);

#endif