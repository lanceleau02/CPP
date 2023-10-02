/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:03:16 by laprieur          #+#    #+#             */
/*   Updated: 2023/10/02 16:50:00 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void) {
	std::cout << YELLOW << "+--------+  CREATION TEST +--------+" << NONE << std::endl;
	std::cout << std::endl;
	{	
		std::cout << "Here we try to create a Bureaucrat with a grade of 151:" << std::endl << std::endl;
		
		try {
			Bureaucrat	Bob("Bob", 151);
		}
		catch (std::exception &e) {
			std::cerr << RED << e.what() << NONE << std::endl;
		}
		
	}
	std::cout << std::endl;
	std::cout << YELLOW << "+--------+ GRADE TOO HIGH CREATION TEST +--------+" << NONE << std::endl;
	std::cout << std::endl;
	return 0;
}