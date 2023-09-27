/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:04:01 by laprieur          #+#    #+#             */
/*   Updated: 2023/09/27 16:56:20 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& name, const unsigned int& grade) : _name(name) {
	if (_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	_grade = grade;
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
		_grade++;
		std::cout << BLUE << "Bureaucrat " << _name << " lost a rank!" << NONE << std::endl;
		return ;
	}
	throw Bureaucrat::GradeTooHighException();
}

void	Bureaucrat::decrementGrade() {
	if (_grade < 150) {
		_grade++;
		std::cout << BLUE << "Bureaucrat " << _name << " lost a rank!" << NONE << std::endl;
		return ;
	}
	throw Bureaucrat::GradeTooLowException();
}

const char*	Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade too high!");
}

const char*	Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade too low!");
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << "." << std::endl;
	return os;
}