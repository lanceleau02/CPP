/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:04:08 by laprieur          #+#    #+#             */
/*   Updated: 2023/10/09 14:30:20 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm(target, 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& source) : AForm(source) {
	*this = source;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& source) {
	if (this != &source)
		_signed = source._signed;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void	PresidentialPardonForm::PresidentialPardon() const {
	std::cout << BLUE << _name << " has been pardoned by Zaphod Beeblebrox." << NONE << std::endl;
}

void	PresidentialPardonForm::execute(const Bureaucrat& executor) const {
	if (_signed == true && executor.getGrade() <= _gradeToExecute)
		this->PresidentialPardon();
	else if (_signed == false && executor.getGrade() <= _gradeToExecute)
		throw AForm::FormNotSignedException();
	else
		throw Bureaucrat::GradeTooLowException();
}