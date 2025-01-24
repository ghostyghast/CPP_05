/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 19:26:45 by amaligno          #+#    #+#             */
/*   Updated: 2025/01/24 18:52:34 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"
#include <string>

class Form{
	public:
		Form();
		Form(std::string name, int sign_grade, int exec_grade);
		~Form();
		Form(const Form &copy);
		Form &operator=(const Form &copy);

		const std::string	&getName() const;
		const bool			&getSigned() const;
		const int			&getSignGrade() const;
		const int			&getExecGrade() const;

		void				beSigned(const Bureaucrat &b);

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
		bool				_signed;
		const int			_signGrade;
		const int			_execGrade;
};

std::ostream	&operator<<(std::ostream &stream, const Form &f);

#endif