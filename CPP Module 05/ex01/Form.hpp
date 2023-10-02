/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:23:55 by laprieur          #+#    #+#             */
/*   Updated: 2023/10/02 15:55:32 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <string>

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		const std::string	_name;
		bool				_signed;
		const unsigned int	_gradeToSign;
		const unsigned int	_gradeToExecute;

		Form();

	public:
		Form(const std::string& name, const unsigned int& gradeToSign, const unsigned int& gradeToExecute);
		Form(const Form& source);
		Form&	operator=(const Form& source);
		~Form();
		
		const std::string&	getName() const;
		const bool&			getSigned() const;
		const unsigned int&	getGradeToSign() const;
		const unsigned int&	getGradeToExecute() const;
		void				beSigned(const Bureaucrat& bureaucrat);
		
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