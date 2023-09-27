/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:03:16 by laprieur          #+#    #+#             */
/*   Updated: 2023/09/27 16:50:33 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void) {
	std::cout << YELLOW << "+--------+ INVALID GRADE CREATION TEST +--------+" << NONE << std::endl;
	std::cout << std::endl;
	{	
		try {
			Bureaucrat	test("Sarko", 151);
		}
		catch (std::exception &e) {
			return 1;
		}
	}
	return 0;
}