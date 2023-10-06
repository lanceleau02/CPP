/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:31:22 by laprieur          #+#    #+#             */
/*   Updated: 2023/10/06 10:53:17 by laprieur         ###   ########.fr       */
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
	
	for (i = 0; i < 3; i++)
		if (formNames[i] == formName)
			break ;
	switch (i) {
		case 0:
			return (new ShrubberyCreationForm(formTarget));
		case 1:
			return (new RobotomyRequestForm(formTarget));
		case 2:
			return (new PresidentialPardonForm(formTarget));
		throw Intern::InvalidFormException();
	}
}

AForm*	Intern::makeForm(const std::string& formName, const std::string& formTarget) {
	try {
		std::cout << "Intern creates " << formName << "." << std::endl;
		return (searchAndCreateForm(formName, formTarget));
	}
	catch (std::exception& e) {
		std::cout << e.what() << formName << "." << std::endl;
		return NULL;
	}
}

const char*	Intern::InvalidFormException::what() const throw() {
	return ("Intern can't create ");
}