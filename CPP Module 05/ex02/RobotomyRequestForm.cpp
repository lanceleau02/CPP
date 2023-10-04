/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:50:45 by laprieur          #+#    #+#             */
/*   Updated: 2023/10/04 12:01:00 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm(target, 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& source) : AForm(source) {
	*this = source;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& source) {
	if (this != &source)
		_signed = source._signed;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void	RobotomyRequestForm::RobotomyRequest() const {
	std::cout << "* Makes some drilling noises. *" << std::endl;
	if (rand() % 2 == 0)
		std::cout << _name << " has been robotomized." << std::endl;
	else
		std::cout << "The robotomy failed." << std::endl;
}

void	RobotomyRequestForm::execute(const Bureaucrat& executor) const {
	if (_signed == true && executor.getGrade() <= _gradeToExecute)
		this->RobotomyRequest();
	else
		throw Bureaucrat::GradeTooLowException();
}