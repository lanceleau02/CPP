/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:03:16 by laprieur          #+#    #+#             */
/*   Updated: 2023/10/09 14:25:03 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void) {
	std::cout << YELLOW << "+--------+ SHRUBBERYCREATIONFORM CLASS TESTS +--------+" << NONE << std::endl;
	std::cout << std::endl;
	{	
		{
			std::cout << "The Bureaucrat can sign and execute the Form:" << std::endl << std::endl;
			
			Bureaucrat				bureaucrat("Bob", 75);
			ShrubberyCreationForm	form("ShrubberyCreation");

			std::cout << bureaucrat;
			std::cout << form << std::endl;
			
			bureaucrat.signForm(form);
			bureaucrat.executeForm(form);
		}
		std::cout << std::endl;
		{
			std::cout << "The Bureaucrat can sign but not execute the Form:" << std::endl << std::endl;
			
			Bureaucrat				bureaucrat("Bob", 140);
			ShrubberyCreationForm	form("ShrubberyCreation");

			std::cout << bureaucrat;
			std::cout << form << std::endl;
			
			bureaucrat.signForm(form);
			bureaucrat.executeForm(form);
		}
		std::cout << std::endl;
		{
			std::cout << "The Bureaucrat cannot sign and execute the Form:" << std::endl << std::endl;
			
			Bureaucrat				bureaucrat("Bob", 146);
			ShrubberyCreationForm	form("ShrubberyCreation");

			std::cout << bureaucrat;
			std::cout << form << std::endl;
			
			bureaucrat.signForm(form);
			bureaucrat.executeForm(form);
		}
		std::cout << std::endl;
		{
			std::cout << "The Bureaucrat cannot execute the Form because it's not signed:" << std::endl << std::endl;
			
			Bureaucrat				bureaucrat("Bob", 1);
			ShrubberyCreationForm	form("ShrubberyCreation");

			std::cout << bureaucrat;
			std::cout << form << std::endl;
			
			bureaucrat.executeForm(form);
		}
	}
	std::cout << std::endl;
	std::cout << YELLOW << "+--------+ ROBOTOMYREQUESTFORM CLASS TESTS +--------+" << NONE << std::endl;
	std::cout << std::endl;
	{
		{
			std::cout << "The Bureaucrat can sign and execute the Form:" << std::endl << std::endl;
			
			Bureaucrat				bureaucrat("Bob", 40);
			RobotomyRequestForm		form("RobotomyRequest");

			std::cout << bureaucrat;
			std::cout << form << std::endl;
			
			bureaucrat.signForm(form);
			bureaucrat.executeForm(form);
		}
		std::cout << std::endl;
		{
			std::cout << "The Bureaucrat can sign but not execute the Form:" << std::endl << std::endl;
			
			Bureaucrat				bureaucrat("Bob", 46);
			RobotomyRequestForm		form("RobotomyRequest");

			std::cout << bureaucrat;
			std::cout << form << std::endl;
			
			bureaucrat.signForm(form);
			bureaucrat.executeForm(form);
		}
		std::cout << std::endl;
		{
			std::cout << "The Bureaucrat cannot sign and execute the Form:" << std::endl << std::endl;
			
			Bureaucrat				bureaucrat("Bob", 73);
			RobotomyRequestForm		form("RobotomyRequest");

			std::cout << bureaucrat;
			std::cout << form << std::endl;
			
			bureaucrat.signForm(form);
			bureaucrat.executeForm(form);
		}
		std::cout << std::endl;
		{
			std::cout << "The Bureaucrat cannot execute the Form because it's not signed:" << std::endl << std::endl;
			
			Bureaucrat				bureaucrat("Bob", 1);
			RobotomyRequestForm		form("RobotomyRequest");

			std::cout << bureaucrat;
			std::cout << form << std::endl;
			
			bureaucrat.executeForm(form);
		}
	}
	std::cout << std::endl;
	std::cout << YELLOW << "+--------+ PRESIDENTIALPARDONFORM CLASS TESTS +--------+" << NONE << std::endl;
	std::cout << std::endl;
	{
		{
			std::cout << "The Bureaucrat can sign and execute the Form:" << std::endl << std::endl;
			
			Bureaucrat				bureaucrat("Bob", 1);
			PresidentialPardonForm	form("PresidentialPardon");

			std::cout << bureaucrat;
			std::cout << form << std::endl;
			
			bureaucrat.signForm(form);
			bureaucrat.executeForm(form);
		}
		std::cout << std::endl;
		{
			std::cout << "The Bureaucrat can sign but not execute the Form:" << std::endl << std::endl;
			
			Bureaucrat				bureaucrat("Bob", 10);
			PresidentialPardonForm	form("PresidentialPardon");

			std::cout << bureaucrat;
			std::cout << form << std::endl;
			
			bureaucrat.signForm(form);
			bureaucrat.executeForm(form);
		}
		std::cout << std::endl;
		{
			std::cout << "The Bureaucrat cannot sign and execute the Form:" << std::endl << std::endl;
			
			Bureaucrat				bureaucrat("Bob", 26);
			PresidentialPardonForm	form("PresidentialPardon");

			std::cout << bureaucrat;
			std::cout << form << std::endl;
			
			bureaucrat.signForm(form);
			bureaucrat.executeForm(form);
		}
		std::cout << std::endl;
		{
			std::cout << "The Bureaucrat cannot execute the Form because it's not signed:" << std::endl << std::endl;
			
			Bureaucrat				bureaucrat("Bob", 1);
			PresidentialPardonForm	form("PresidentialPardon");

			std::cout << bureaucrat;
			std::cout << form << std::endl;
			
			bureaucrat.executeForm(form);
		}
	}
	return 0;
}