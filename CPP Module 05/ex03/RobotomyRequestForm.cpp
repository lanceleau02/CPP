/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:50:45 by laprieur          #+#    #+#             */
/*   Updated: 2023/10/10 14:37:55 by laprieur         ###   ########.fr       */
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
	static int	rand;
	
	std::cout << BLUE << "* Makes some drilling noises. *" << NONE << std::endl;
	if (rand++ % 2 == 0)
		std::cout << GREEN << _name << " has been robotomized." << NONE << std::endl;
	else
		std::cout << RED << "The robotomy failed." << NONE << std::endl;
}

void	RobotomyRequestForm::execute(const Bureaucrat& executor) const {
	if (_signed == true && executor.getGrade() <= _gradeToExecute)
		this->RobotomyRequest();
	else if (_signed == false && executor.getGrade() <= _gradeToExecute)
		throw AForm::FormNotSignedException();
	else
		throw Bureaucrat::GradeTooLowException();
}