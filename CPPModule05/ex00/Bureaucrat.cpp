/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:04:01 by laprieur          #+#    #+#             */
/*   Updated: 2023/10/09 13:28:50 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& name, const unsigned int& grade) : _name(name) {
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& source) : _name(source._name) {
	*this = source;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& source) {
	if (this != &source)
		_grade = source._grade;
	return *this;
}

Bureaucrat::~Bureaucrat() {}

const std::string&	Bureaucrat::getName() const {
	return _name;
}

const unsigned int&	Bureaucrat::getGrade() const {
	return _grade;
}

void	Bureaucrat::incrementGrade() {
	if (_grade > 1) {
		_grade--;
		std::cout << GREEN << "Bureaucrat " << _name << " got a promotion!" << NONE << std::endl;
	}
	else
		throw Bureaucrat::GradeTooHighException();
}

void	Bureaucrat::decrementGrade() {
	if (_grade < 150) {
		_grade++;
		std::cout << RED << "Bureaucrat " << _name << " lost a rank!" << NONE << std::endl;
	}
	else
		throw Bureaucrat::GradeTooLowException();
}

const char*	Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade too high!");
}

const char*	Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade too low!");
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
	os << BLUE << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << "." << NONE << std::endl;
	return os;
}