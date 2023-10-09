/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:23:55 by laprieur          #+#    #+#             */
/*   Updated: 2023/10/09 13:10:22 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <string>

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	protected:
		const std::string	_name;
		bool				_signed;
		const unsigned int	_gradeToSign;
		const unsigned int	_gradeToExecute;

		AForm();

	public:
		AForm(const std::string& name, const unsigned int& gradeToSign, const unsigned int& gradeToExecute);
		AForm(const AForm& source);
		AForm&	operator=(const AForm& source);
		virtual ~AForm();
		
		const std::string&	getName() const;
		const bool&			getSigned() const;
		const unsigned int&	getGradeToSign() const;
		const unsigned int&	getGradeToExecute() const;
		void				beSigned(const Bureaucrat& bureaucrat);
		virtual void		execute(const Bureaucrat& executor) const = 0;
		
		class GradeTooHighException : public std::exception {
			public:
    			virtual const char* what() const throw();
		};
		
		class GradeTooLowException : public std::exception {
			public:
    			virtual const char* what() const throw();
		};
		
		class FormNotSignedException : public std::exception {
			public:
    			virtual const char* what() const throw();
		};
};

std::ostream&	operator<<(std::ostream& os, const AForm& form);

#endif