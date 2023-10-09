/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:58:46 by laprieur          #+#    #+#             */
/*   Updated: 2023/10/09 14:30:39 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(const std::string& name, const unsigned int& gradeToSign, const unsigned int& gradeToExecute)
	: _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {}

AForm::AForm(const AForm& source) : _name(source._name), _gradeToSign(source._gradeToSign), _gradeToExecute(source._gradeToExecute) {
	*this = source;
}

AForm&	AForm::operator=(const AForm& source) {
	if (this != &source)
		_signed = source._signed;
	return *this;
}

AForm::~AForm() {}

const std::string&	AForm::getName() const {
	return _name;
}

const bool&	AForm::getSigned() const {
	return _signed;
}

const unsigned int&	AForm::getGradeToSign() const {
	return _gradeToSign;
}

const unsigned int&	AForm::getGradeToExecute() const {
	return _gradeToExecute;
}

void	AForm::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() <= _gradeToSign)
		_signed = true;
	else
		throw AForm::GradeTooLowException();
}
		
const char*	AForm::GradeTooHighException::what() const throw() {
	return ("Grade too high!");
}

const char*	AForm::GradeTooLowException::what() const throw() {
	return ("Grade too low!");
}

const char*	AForm::FormNotSignedException::what() const throw() {
	return ("Form not signed!");
}

std::ostream&	operator<<(std::ostream& os, const AForm& form) {
	if (form.getSigned() == false)
		os << BLUE << "Form " << form.getName() << " is not signed. Grade required to sign it: " << form.getGradeToSign() << ", grade required to execute it: " << form.getGradeToExecute() << "." << NONE << std::endl;
	else if (form.getSigned() == true)
		os << BLUE << "Form " << form.getName() << " is signed. Grade required to sign it: " << form.getGradeToSign() << ", grade required to execute it: " << form.getGradeToExecute() << "." << NONE << std::endl;
	return os;
}