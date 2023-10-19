/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:36:15 by laprieur          #+#    #+#             */
/*   Updated: 2023/10/19 15:56:18 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>

#define UNDERLINE "\033[4m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define NONE	"\033[0m"

int	main(void) {
	std::cout << YELLOW << "+--------+ SUBJECT TESTS +--------+" << NONE << std::endl;
	std::cout << std::endl;
	{
		int a = 2;
		int b = 3;
		
		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		
		std::string c = "chaine1";
		std::string d = "chaine2";
		
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}
	std::cout << std::endl;
	std::cout << YELLOW << "+--------+ swap() FUNCTION TESTS +--------+" << NONE << std::endl;
	std::cout << std::endl;
	{
		std::cout << UNDERLINE BLUE << "Test with integers:" << NONE << std::endl << std::endl;
		{
			int	a = 0;
			int	b = 42;
			
			std::cout << "Values before the swap: a = " << a << " ; b = " << b << std::endl << std::endl;
			swap(a, b);
			std::cout << "Values after the swap: a = " << a << " ; b = " << b << std::endl;
		}
		std::cout << std::endl;
		std::cout << UNDERLINE BLUE << "Test with characters:" << NONE << std::endl << std::endl;
		{
			char	a = '4';
			char	b = '2';
			
			std::cout << "Values before the swap: a = " << a << " ; b = " << b << std::endl << std::endl;
			swap(a, b);
			std::cout << "Values after the swap: a = " << a << " ; b = " << b << std::endl;
		}
		std::cout << std::endl;
		std::cout << UNDERLINE BLUE << "Test with strings:" << NONE << std::endl << std::endl;
		{
			std::string	a = "Forty";
			std::string	b = "Two";
			
			std::cout << "Values before the swap: a = " << a << " ; b = " << b << std::endl << std::endl;
			swap(a, b);
			std::cout << "Values after the swap: a = " << a << " ; b = " << b << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << YELLOW << "+--------+ min() FUNCTION TESTS +--------+" << NONE << std::endl;
	std::cout << std::endl;
	{
		std::cout << UNDERLINE BLUE << "Test with integers:" << NONE << std::endl << std::endl;
		{
			int	a = 0;
			int	b = 42;
			
			std::cout << "The smallest value between " << a << " and " << b << " is " << min(a, b) << std::endl;
		}
		std::cout << std::endl;
		std::cout << UNDERLINE BLUE << "Test with equal integers:" << NONE << std::endl << std::endl;
		{
			int	a = 42;
			int	b = 42;
			
			std::cout << "The smallest value between " << a << " and " << b << " is " << min(a, b) << std::endl;
			std::cout << std::endl;
			std::cout << "Address of b: " << &b << std::endl;
			std::cout << "Return address of max() function: " << &min(a, b) << std::endl;
		}
		std::cout << std::endl;
		std::cout << UNDERLINE BLUE << "Test with characters:" << NONE << std::endl << std::endl;
		{
			char	a = '4';
			char	b = '2';
			
			std::cout << "The smallest value between " << a << " and " << b << " is " << min(a, b) << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << YELLOW << "+--------+ max() FUNCTION TESTS +--------+" << NONE << std::endl;
	std::cout << std::endl;
	{
		std::cout << UNDERLINE BLUE << "Test with integers:" << NONE << std::endl << std::endl;
		{
			int	a = 0;
			int	b = 42;
			
			std::cout << "The biggest value between " << a << " and " << b << " is " << max(a, b) << std::endl;
		}
		std::cout << std::endl;
		std::cout << UNDERLINE BLUE << "Test with equal integers:" << NONE << std::endl << std::endl;
		{
			int	a = 42;
			int	b = 42;
			
			std::cout << "The biggest value between " << a << " and " << b << " is " << max(a, b) << std::endl;
			std::cout << std::endl;
			std::cout << "Address of b: " << &b << std::endl;
			std::cout << "Return address of max() function: " << &max(a, b) << std::endl;
		}
		std::cout << std::endl;
		std::cout << UNDERLINE BLUE << "Test with characters:" << NONE << std::endl << std::endl;
		{
			char	a = '4';
			char	b = '2';
			
			std::cout << "The biggest value between " << a << " and " << b << " is " << max(a, b) << std::endl;
		}
	}
	return 0;
}