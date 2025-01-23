/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 19:26:45 by amaligno          #+#    #+#             */
/*   Updated: 2025/01/23 20:10:29 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"
#include <string>

class Form{
	public:
		Form();
		Form(std::string name, int grade);
		~Form();
		Form(const Form &copy);
		Form &operator=(const Form &copy);

		const std::string	&getName() const;
		const bool			&getSign() const;
		const int			&getGrade() const;

		void				beSigned(Bureaucrat &b);

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
		bool				_sign;
		const int			_signGrade;
		const int			_execGrade;
};

std::ostream	&operator<<(std::ostream &stream, const Form &f);

#endif