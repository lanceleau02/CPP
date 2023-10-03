/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:03:16 by laprieur          #+#    #+#             */
/*   Updated: 2023/10/03 15:59:29 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void) {
	std::cout << YELLOW << "+--------+ FIRST TEST +--------+" << NONE << std::endl;
	std::cout << std::endl;
	{	
		Bureaucrat	Bob("Bob", 1);
		Form		Squarepants("Squarepants", 75, 75);

		std::cout << BLUE << Bob << NONE;
		std::cout << BLUE << Squarepants << NONE << std::endl;

		Bob.signForm(Squarepants);
	}
	std::cout << std::endl;
	std::cout << YELLOW << "+--------+ SECOND TEST +--------+" << NONE << std::endl;
	std::cout << std::endl;
	{	
		Bureaucrat	Bob("Bob", 75);
		Form		Squarepants("Squarepants", 75, 75);

		std::cout << BLUE << Bob << NONE;
		std::cout << BLUE << Squarepants << NONE << std::endl;

		Bob.signForm(Squarepants);
	}
	std::cout << std::endl;
	std::cout << YELLOW << "+--------+ THIRD TEST +--------+" << NONE << std::endl;
	std::cout << std::endl;
	{	
		Bureaucrat	Bob("Bob", 150);
		Form		Squarepants("Squarepants", 75, 75);

		std::cout << BLUE << Bob << NONE;
		std::cout << BLUE << Squarepants << NONE << std::endl;

		Bob.signForm(Squarepants);
	}
	return 0;
}