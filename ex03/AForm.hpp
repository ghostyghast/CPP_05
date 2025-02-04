/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 19:26:45 by amaligno          #+#    #+#             */
/*   Updated: 2025/01/31 17:28:43 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"
#include <string>

class AForm{
	public:
		AForm();
		AForm(std::string name, int sign_grade, int exec_grade);
		~AForm();
		AForm(const AForm &copy);
		AForm &operator=(const AForm &copy);

		const std::string	&getName() const;
		const bool			&getSigned() const;
		const int			&getSignGrade() const;
		const int			&getExecGrade() const;

		void				execute(Bureaucrat const &executor) const;

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
		class FormNotSignedException : public std::exception
		{
			public:
				const char	*what() const throw();	
		};
	
	private:
		virtual void		performExecute() const = 0;
		const std::string	_name;
		bool				_signed;
		const int			_signGrade;
		const int			_execGrade;
};

std::ostream	&operator<<(std::ostream &stream, const AForm &f);

#endif