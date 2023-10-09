/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:03:16 by laprieur          #+#    #+#             */
/*   Updated: 2023/10/09 14:12:35 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void) {
	std::cout << YELLOW << "+--------+ GRADE TOO LOW CREATION TEST +--------+" << NONE << std::endl;
	std::cout << std::endl;
	{	
		std::cout << "Here we try to create a Bureaucrat with a grade of 151:" << std::endl << std::endl;
		
		try {
			Bureaucrat	bob("Bob", 151);
		}
		catch (std::exception &e) {
			std::cerr << RED << e.what() << NONE << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << YELLOW << "+--------+ GRADE TOO HIGH CREATION TEST +--------+" << NONE << std::endl;
	std::cout << std::endl;
	{	
		std::cout << "Here we try to create a Bureaucrat with a grade of 0:" << std::endl << std::endl;
		
		try {
			Bureaucrat	bob("Bob", 0);
		}
		catch (std::exception& e) {
			std::cerr << RED << e.what() << NONE << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << YELLOW << "+--------+ incrementGrade() FUNCTION TEST +--------+" << NONE << std::endl;
	std::cout << std::endl;
	{	
		std::cout << "Here we create two Bureaucrats:" << std::endl << std::endl;
		
		Bureaucrat	bob("Bob", 150);
		Bureaucrat	patrick("Patrick", 1);
		
		std::cout << bob;
		std::cout << patrick;

		std::cout << std::endl << "Now we will try to increment the grade of our two Bureaucrats:" << std::endl << std::endl;
		
		try {	
			bob.incrementGrade();
			patrick.incrementGrade();
		}
		catch (std::exception& e) {
			std::cerr << RED << e.what() << NONE << std::endl << std::endl;
		}
		
		std::cout << bob;
		std::cout << patrick;
	}
	std::cout << std::endl;
	std::cout << YELLOW << "+--------+ decrementGrade() FUNCTION TEST +--------+" << NONE << std::endl;
	std::cout << std::endl;
	{	
		std::cout << "Here we create two Bureaucrats:" << std::endl << std::endl;
		
		Bureaucrat	bob("Bob", 1);
		Bureaucrat	patrick("Patrick", 150);
	
		std::cout << bob;
		std::cout << patrick;

		std::cout << std::endl << "Now we will try to decrement the grade of our two Bureaucrats:" << std::endl << std::endl;
		
		try {	
			bob.decrementGrade();
			patrick.decrementGrade();
		}
		catch (std::exception& e) {
			std::cerr << RED << e.what() << NONE << std::endl << std::endl;
		}
		
		std::cout << bob;
		std::cout << patrick;
	}
	return 0;
}