/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:33:40 by laprieur          #+#    #+#             */
/*   Updated: 2023/10/02 16:49:47 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string& name, const unsigned int& gradeToSign, const unsigned int& gradeToExecute)
	: _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {}

Form::Form(const Form& source) : _name(source._name), _gradeToSign(source._gradeToSign), _gradeToExecute(source._gradeToExecute) {
	*this = source;
}

Form&	Form::operator=(const Form& source) {
	if (this != &source)
		_signed = source._signed;
	return *this;
}

Form::~Form() {}

const std::string&	Form::getName() const {
	return _name;
}

const bool&	Form::getSigned() const {
	return _signed;
}

const unsigned int&	Form::getGradeToSign() const {
	return _gradeToSign;
}

const unsigned int&	Form::getGradeToExecute() const {
	return _gradeToExecute;
}

void	Form::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat._grade <= _gradeToSign) {
		_signed = true;
		bureaucrat.signForm();
	}
	else
		throw Bureaucrat::GradeTooLowException();
}
		
const char*	Form::GradeTooHighException::what() const throw() {
	return ("Grade too high!");
}

const char*	Form::GradeTooLowException::what() const throw() {
	return ("Grade too low!");
}

std::ostream&	operator<<(std::ostream& os, const Form& form) {
	if (_signed == false)
		os << "Form " << _name << " is not signed. Grade required to sign it: " << _gradeToSign << ", grade required to execute it: " << _gradeToExecute << "." << std::endl;
	else if (_signed == true)
		os << "Form " << _name << " is signed. Grade required to sign it: " << _gradeToSign << ", grade required to execute it: " << _gradeToExecute << "." << std::endl;
	return os;
}