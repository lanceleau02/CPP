/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:31:22 by laprieur          #+#    #+#             */
/*   Updated: 2023/10/09 11:43:57 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

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
	std::string		formNames[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	int				i;
	
	if (formName.empty() || formTarget.empty()) {
		std::cerr << RED << "Intern can't create a form without a form name or target!" << NONE << std::endl;
		return NULL;
	}
	for (i = 0; i < 3; i++)
		if (formNames[i] == formName)
			break ;
	switch (i) {
		case 0:
			std::cout << GREEN << "Intern creates " << formName << "." << NONE << std::endl;
			return (new ShrubberyCreationForm(formTarget));
		case 1:
			std::cout << GREEN << "Intern creates " << formName << "." << NONE << std::endl;
			return (new RobotomyRequestForm(formTarget));
		case 2:
			std::cout << GREEN << "Intern creates " << formName << "." << NONE << std::endl;
			return (new PresidentialPardonForm(formTarget));
		default:
			throw Intern::InvalidFormException();
	}
	return NULL;
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