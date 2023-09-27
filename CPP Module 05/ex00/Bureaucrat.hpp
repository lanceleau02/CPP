/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:03:28 by laprieur          #+#    #+#             */
/*   Updated: 2023/09/27 16:51:25 by laprieur         ###   ########.fr       */
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

class Bureaucrat {
	private:
		const std::string	_name;
		unsigned int		_grade;
	
	public:
		Bureaucrat(const std::string& name, const unsigned int& grade);
		~Bureaucrat();
		
		const std::string&	getName() const;
		const unsigned int&	getGrade() const;
		void				incrementGrade();
		void				decrementGrade();
		
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