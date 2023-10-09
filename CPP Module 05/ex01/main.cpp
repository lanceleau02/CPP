/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:03:16 by laprieur          #+#    #+#             */
/*   Updated: 2023/10/09 14:45:13 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void) {
	std::cout << YELLOW << "+--------+ FORM CLASS TESTS +--------+" << NONE << std::endl;
	std::cout << std::endl;
	{	
		std::cout << "The Bureaucrat can sign and execute the Form:" << std::endl << std::endl;
		{
			Bureaucrat	bob("Bob", 1);
			Form		squarepants("Squarepants", 75, 75);

			std::cout << bob;
			std::cout << squarepants << std::endl;

			bob.signForm(squarepants);
		}
		std::cout << std::endl;
		std::cout << "The Bureaucrat cannot sign and execute the Form:" << std::endl << std::endl;
		{
			Bureaucrat	bob("Bob", 150);
			Form		squarepants("Squarepants", 75, 75);

			std::cout << bob;
			std::cout << squarepants << std::endl;

			bob.signForm(squarepants);
		}
	}
	return 0;
}