/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:31:22 by laprieur          #+#    #+#             */
/*   Updated: 2023/10/04 15:57:09 by laprieur         ###   ########.fr       */
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

void	searchAndCreateForm(const std::string& formName) const {
	std::string	formNames[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	
	for (int i = 0; i < 3; i++)
		if (formNames[i] == formName)
			
	throw Intern::InvalidFormNameException();
}

AForm*	Intern::makeForm(const std::string& formName, const std::string& formTarget) {
	try {
		searchAndCreateForm(formName);
	}
	catch (std::exception& e) {
		return 1;
	}
}

const char*	Intern::InvalidFormNameException::what() const throw() {
	return ("Invalid form name!");
}