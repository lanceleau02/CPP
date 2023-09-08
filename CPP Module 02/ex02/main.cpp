/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 14:47:26 by laprieur          #+#    #+#             */
/*   Updated: 2023/09/08 15:12:03 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#define NONE	"\033[0m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define PURPLE	"\033[35m"

int	main(void) {
	std::cout << YELLOW << "+--------+ SUBJECT TESTS +--------+" << NONE << std::endl << std::endl;
	{
		Fixed		a;
		Fixed const	b(Fixed(5.05f) * Fixed(2));

		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;

		std::cout << b << std::endl;

		std::cout << Fixed::max(a, b) << std::endl;
	}
	std::cout << std::endl;
	std::cout << YELLOW << "+--------+ MY TESTS +--------+" << NONE << std::endl << std::endl;
	{
		Fixed	a;
		Fixed	b(Fixed(5.05f) * Fixed(2));
		
		// +--------+ GREATER THAN OR EQUAL TO +--------+
		
		std::cout << PURPLE << ">= operator: a >= b" << NONE << std::endl << std::endl;
		
		if (a >= b)
			std::cout << BLUE << a << NONE << std::endl;
		else
			std::cout << BLUE << b << NONE << std::endl;

		// +--------+ LESS THAN OR EQUAL TO +--------+
		
		std::cout << std::endl;
		std::cout << PURPLE << "<= operator:" << NONE << std::endl << std::endl;
		
		if (a <= b)
			std::cout << BLUE << a << NONE << std::endl;
		else
			std::cout << BLUE << b << NONE << std::endl;
			
		// +--------+ EQUAL TO +--------+
			
		std::cout << std::endl;
		std::cout << PURPLE << "== operator:" << NONE << std::endl << std::endl;
		
		if (a == b)
			std::cout << BLUE << "a and b are equal." << NONE << std::endl;
		else
			std::cout << BLUE << "a and b aren't equal." << NONE << std::endl;
			
		// +--------+ NOT EQUAL TO +--------+
			
		std::cout << std::endl;
		std::cout << PURPLE << "!= operator:" << NONE << std::endl << std::endl;
		
		if (a != b)
			std::cout << BLUE << "a and b aren't equal." << NONE << std::endl;
		else
			std::cout << BLUE << "a and b are equal." << NONE << std::endl;
			
		// +--------+ PLUS +--------+
			
		std::cout << std::endl;
		std::cout << PURPLE << "+ operator:" << NONE << std::endl << std::endl;
		
		std::cout << BLUE << a + b << NONE << std::endl;
		
		// +--------+ MINUS +--------+
		
		std::cout << std::endl;
		std::cout << PURPLE << "- operator:" << NONE << std::endl << std::endl;
		
		std::cout << BLUE << a - b << NONE << std::endl;
		
		// +--------+ TIMES +--------+
		
		std::cout << std::endl;
		std::cout << PURPLE << "* operator:" << NONE << std::endl << std::endl;
		
		std::cout << BLUE << a * b << NONE << std::endl;
		
		// +--------+ DIVIDE +--------+

		std::cout << std::endl;
		std::cout << PURPLE << "/ operator:" << NONE << std::endl << std::endl;
		
		std::cout << BLUE << a / b << NONE << std::endl;
		
		// +--------+ min() +--------+

		std::cout << std::endl;
		std::cout << PURPLE << "min() function:" << NONE << std::endl << std::endl;
		
		std::cout << BLUE << Fixed::min(a, b) << NONE << std::endl;
		
		// +--------+ min(const) +--------+

		std::cout << std::endl;
		std::cout << PURPLE << "min(const) function:" << NONE << std::endl << std::endl;
		
		std::cout << BLUE << Fixed::min((const Fixed&)a, (const Fixed&)b) << NONE << std::endl;
		
		// +--------+ max() +--------+
		
		std::cout << std::endl;
		std::cout << PURPLE << "max() function:" << NONE << std::endl << std::endl;
		
		std::cout << BLUE << Fixed::max(a, b) << NONE << std::endl;
		
		// +--------+ max(const) +--------+

		std::cout << std::endl;
		std::cout << PURPLE << "max(const) function:" << NONE << std::endl << std::endl;
		
		std::cout << BLUE << Fixed::max((const Fixed&)a, (const Fixed&)b) << NONE << std::endl;
		std::cout << std::endl;
	}
}