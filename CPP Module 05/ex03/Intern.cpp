/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:31:22 by laprieur          #+#    #+#             */
/*   Updated: 2023/10/10 14:35:11 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

static AForm*	shrubberyCreationFormBuilder(const std::string& formTarget) {
	return (new ShrubberyCreationForm(formTarget));
}

static AForm*	robotomyRequestFormBuilder(const std::string& formTarget) {
	return (new RobotomyRequestForm(formTarget));
}

static AForm*	presidentialPardonFormBuilder(const std::string& formTarget) {
	return (new PresidentialPardonForm(formTarget));
}

Intern::Intern() {}

Intern::Intern(const Intern& source) {
	*this = source;
}

Intern& Intern::operator=(const Intern& source) {
	(void)source;
	return *this;
}

Intern::~Intern() {}

AForm*	Intern::searchAndCreateForm(const std::string& formName, const std::string& formTarget) {
	std::string	formNames[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	AForm*		(*formBuilders[3])(const std::string&) = {shrubberyCreationFormBuilder, robotomyRequestFormBuilder, presidentialPardonFormBuilder};
	int			i;
	
	if (formName.empty() || formTarget.empty()) {
		std::cerr << RED << "Intern can't create a form without a form name or a target!" << NONE << std::endl;
		return NULL;
	}
	for (i = 0; i < 3; i++) {
		if (formNames[i] == formName) {
			std::cout << GREEN << "Intern creates " << formName << "." << NONE << std::endl;
			return formBuilders[i](formName);
		}
	}
	throw Intern::InvalidFormException();
}

AForm*	Intern::makeForm(const std::string& formName, const std::string& formTarget) {
	try {
		return (searchAndCreateForm(formName, formTarget));
	}
	catch (std::exception& e) {
		std::cerr << RED << e.what() << formName << "." << NONE << std::endl;
		return NULL;
	}
}

const char*	Intern::InvalidFormException::what() const throw() {
	return ("Intern can't create ");
}