/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:03:28 by laprieur          #+#    #+#             */
/*   Updated: 2023/10/03 11:20:24 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define NONE	"\033[0m"

#include "Form.hpp"

class Form;

class Bureaucrat {
	private:
		const std::string	_name;
		unsigned int		_grade;

		Bureaucrat();
		
	public:
		Bureaucrat(const std::string& name, const unsigned int& grade);
		Bureaucrat(const Bureaucrat& source);
		Bureaucrat&	operator=(const Bureaucrat& source);
		~Bureaucrat();
		
		const std::string&	getName() const;
		const unsigned int&	getGrade() const;
		void				incrementGrade();
		void				decrementGrade();
		void				signForm(Form& form) const;
		
		class GradeTooHighException : public std::exception {
			public:
    			virtual const char* what() const throw();
		};
		
		class GradeTooLowException : public std::exception {
			public:
    			virtual const char* what() const throw();
		};
};

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif