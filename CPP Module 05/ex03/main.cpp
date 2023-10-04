/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:03:16 by laprieur          #+#    #+#             */
/*   Updated: 2023/10/04 14:59:12 by laprieur         ###   ########.fr       */
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
			std::cout << "Test: the bureaucrat can sign and execute the form." << std::endl << std::endl;
			
			Bureaucrat				bureaucrat("Bob", 75);
			ShrubberyCreationForm	form("ShrubberyForm");

			std::cout
				<< BLUE << bureaucrat
				<< BLUE << form << NONE << std::endl;
			
			bureaucrat.signForm(form);
			bureaucrat.executeForm(form);
		}
		std::cout << std::endl;
		{
			std::cout << "Test: the bureaucrat can sign but not execute the form." << std::endl << std::endl;
			
			Bureaucrat				bureaucrat("Bob", 140);
			ShrubberyCreationForm	form("ShrubberyForm");

			std::cout
				<< BLUE << bureaucrat
				<< BLUE << form << NONE << std::endl;
			
			bureaucrat.signForm(form);
			bureaucrat.executeForm(form);
		}
		std::cout << std::endl;
		{
			std::cout << "Test: the bureaucrat cannot sign and execute the form." << std::endl << std::endl;
			
			Bureaucrat				bureaucrat("Bob", 146);
			ShrubberyCreationForm	form("ShrubberyForm");

			std::cout
				<< BLUE << bureaucrat
				<< BLUE << form << NONE << std::endl;
			
			bureaucrat.signForm(form);
			bureaucrat.executeForm(form);
		}
	}
	std::cout << std::endl;
	std::cout << YELLOW << "+--------+ ROBOTOMYREQUESTFORM CLASS TESTS +--------+" << NONE << std::endl;
	std::cout << std::endl;
	{
		{
			std::cout << "Test: the bureaucrat can sign and execute the form." << std::endl << std::endl;
			
			Bureaucrat				bureaucrat("Bob", 40);
			RobotomyRequestForm		form("RobotomyForm");

			std::cout
				<< BLUE << bureaucrat
				<< BLUE << form << NONE << std::endl;
			
			bureaucrat.signForm(form);
			bureaucrat.executeForm(form);
		}
		std::cout << std::endl;
		{
			std::cout << "Test: the bureaucrat can sign but not execute the form." << std::endl << std::endl;
			
			Bureaucrat				bureaucrat("Bob", 46);
			RobotomyRequestForm		form("RobotomyForm");

			std::cout
				<< BLUE << bureaucrat
				<< BLUE << form << NONE << std::endl;
			
			bureaucrat.signForm(form);
			bureaucrat.executeForm(form);
		}
		std::cout << std::endl;
		{
			std::cout << "Test: the bureaucrat cannot sign and execute the form." << std::endl << std::endl;
			
			Bureaucrat				bureaucrat("Bob", 73);
			RobotomyRequestForm		form("RobotomyForm");

			std::cout
				<< BLUE << bureaucrat
				<< BLUE << form << NONE << std::endl;
			
			bureaucrat.signForm(form);
			bureaucrat.executeForm(form);
		}
	}
	std::cout << std::endl;
	std::cout << YELLOW << "+--------+ PRESIDENTIALPARDONFORM CLASS TESTS +--------+" << NONE << std::endl;
	std::cout << std::endl;
	{
		{
			std::cout << "Test: the bureaucrat can sign and execute the form." << std::endl << std::endl;
			
			Bureaucrat				bureaucrat("Bob", 1);
			PresidentialPardonForm	form("PresidentialForm");

			std::cout
				<< BLUE << bureaucrat
				<< BLUE << form << NONE << std::endl;
			
			bureaucrat.signForm(form);
			bureaucrat.executeForm(form);
		}
		std::cout << std::endl;
		{
			std::cout << "Test: the bureaucrat can sign but not execute the form." << std::endl << std::endl;
			
			Bureaucrat				bureaucrat("Bob", 10);
			PresidentialPardonForm	form("PresidentialForm");

			std::cout
				<< BLUE << bureaucrat
				<< BLUE << form << NONE << std::endl;
			
			bureaucrat.signForm(form);
			bureaucrat.executeForm(form);
		}
		std::cout << std::endl;
		{
			std::cout << "Test: the bureaucrat cannot sign and execute the form." << std::endl << std::endl;
			
			Bureaucrat				bureaucrat("Bob", 26);
			PresidentialPardonForm	form("PresidentialForm");

			std::cout
				<< BLUE << bureaucrat
				<< BLUE << form << NONE << std::endl;
			
			bureaucrat.signForm(form);
			bureaucrat.executeForm(form);
		}
	}
	return 0;
}