/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:03:16 by laprieur          #+#    #+#             */
/*   Updated: 2023/10/09 14:39:50 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(void) {
	std::cout << YELLOW << "+--------+ SUBJECT TESTS +--------+" << NONE << std::endl;
	std::cout << std::endl;
	{
		AForm*	rrf;
		Intern	someRandomIntern;
		
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	}
	std::cout << std::endl;
	std::cout << YELLOW << "+--------+ INTERN CLASS TESTS +--------+" << NONE << std::endl;
	std::cout << std::endl;
	{
		std::cout << "Intern tries to create a form named \"ShrubberyCreationForm\":" << std::endl << std::endl;
		{	
			AForm*		form;
			Intern		intern;

			form = intern.makeForm("ShrubberyCreationForm", "target");
			delete form;
		}
		std::cout << std::endl;
		std::cout << "Intern tries to create a form named \"RobotomyRequestForm\":" << std::endl << std::endl;
		{	
			AForm*		form;
			Intern		intern;

			form = intern.makeForm("RobotomyRequestForm", "target");
			delete form;
		}
		std::cout << std::endl;
		std::cout << "Intern tries to create a form named \"PresidentialPardonForm\":" << std::endl << std::endl;
		{	
			AForm*		form;
			Intern		intern;

			form = intern.makeForm("PresidentialPardonForm", "target");
			delete form;
		}
		std::cout << std::endl;
		std::cout << "Intern tries to create a form named \"form\":" << std::endl << std::endl;
		{
			AForm*	form;
			Intern	intern;

			form = intern.makeForm("form", "target");
			delete form;
		}
		std::cout << std::endl;
		std::cout << "Intern tries to create a form without a name:" << std::endl << std::endl;
		{
			AForm*	form;
			Intern	intern;

			form = intern.makeForm("", "target");
			delete form;
		}
		std::cout << std::endl;
		std::cout << "Intern tries to create a form without a target:" << std::endl << std::endl;
		{
			AForm*	form;
			Intern	intern;

			form = intern.makeForm("Form", "");
			delete form;
		}
	}
	return 0;
}