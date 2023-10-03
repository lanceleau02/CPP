/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:23:55 by laprieur          #+#    #+#             */
/*   Updated: 2023/10/03 17:00:25 by laprieur         ###   ########.fr       */
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

		Form();

	public:
		Form(const std::string& name, const unsigned int& gradeToSign, const unsigned int& gradeToExecute);
		Form(const Form& source);
		Form&	operator=(const Form& source);
		virtual ~Form();
		
		const std::string&	getName() const;
		const bool&			getSigned() const;
		const unsigned int&	getGradeToSign() const;
		const unsigned int&	getGradeToExecute() const;
		virtual void		beSigned(const Bureaucrat& bureaucrat) = 0;
		
		class GradeTooHighException : public std::exception {
			public:
    			virtual const char* what() const throw();
		};
		
		class GradeTooLowException : public std::exception {
			public:
    			virtual const char* what() const throw();
		};
};

std::ostream&	operator<<(std::ostream& os, const Form& form);

#endif