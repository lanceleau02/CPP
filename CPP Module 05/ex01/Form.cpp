/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:33:40 by laprieur          #+#    #+#             */
/*   Updated: 2023/10/09 13:41:00 by laprieur         ###   ########.fr       */
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
	if (bureaucrat.getGrade() <= _gradeToSign)
		_signed = true;
	else
		throw Form::GradeTooLowException();
}
		
const char*	Form::GradeTooHighException::what() const throw() {
	return ("Grade too high!");
}

const char*	Form::GradeTooLowException::what() const throw() {
	return ("Grade too low!");
}

std::ostream&	operator<<(std::ostream& os, const Form& form) {
	if (form.getSigned() == false)
		os << BLUE << "Form " << form.getName() << " is not signed. Grade required to sign it: " << form.getGradeToSign() << ", grade required to execute it: " << form.getGradeToExecute() << "." << NONE << std::endl;
	else if (form.getSigned() == true)
		os << BLUE << "Form " << form.getName() << " is signed. Grade required to sign it: " << form.getGradeToSign() << ", grade required to execute it: " << form.getGradeToExecute() << "." << NONE << std::endl;
	return os;
}