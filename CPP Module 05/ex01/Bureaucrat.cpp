/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:04:01 by laprieur          #+#    #+#             */
/*   Updated: 2023/10/02 16:46:54 by laprieur         ###   ########.fr       */
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
		return ;
	}
	throw Bureaucrat::GradeTooHighException();
}

void	Bureaucrat::decrementGrade() {
	if (_grade < 150) {
		_grade++;
		std::cout << RED << "Bureaucrat " << _name << " lost a rank!" << NONE << std::endl;
		return ;
	}
	throw Bureaucrat::GradeTooLowException();
}

void	Bureaucrat::signForm(const Form& form) const {
	if (form._signed == true)
		std::cout << _name << " signed " << form._name << "." << std::endl;
	else if (form._signed == false)
		std::cout << _name << " couldn't sign " << form._name << " because his grade is " << _grade << " and the required grade is " << _gradeToSign << "." << std::endl;
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