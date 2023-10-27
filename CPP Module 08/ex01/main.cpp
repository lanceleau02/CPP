/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:54:42 by laprieur          #+#    #+#             */
/*   Updated: 2023/10/27 16:01:12 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#include <iostream>

#define UNDERLINE "\033[4m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define NONE	"\033[0m"

int main() {
	std::cout << YELLOW << "+--------+ SUBJECT TESTS +--------+" << NONE << std::endl;
	std::cout << std::endl;
	{
		Span	sp = Span(5);
		
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	std::cout << std::endl;
	std::cout << YELLOW << "+--------+ shortestSpan() & longestSpan() FUNCTIONS TESTS +--------+" << NONE << std::endl;
	std::cout << std::endl;
	{
		std::cout << UNDERLINE BLUE << "No numbers stored:" << NONE << std::endl;
		std::cout << std::endl;
		{
			Span	sp = Span(5);

			try {
				std::cout << sp.shortestSpan() << std::endl;
			}
			catch (std::exception& e) {
				std::cout << e.what() << std::endl;
			}
		}
		std::cout << std::endl;
		std::cout << UNDERLINE BLUE << "Not enough numbers stored:" << NONE << std::endl;
		std::cout << std::endl;
		{
			Span	sp = Span(5);

			sp.addNumber(5);

			try {
				std::cout << sp.shortestSpan() << std::endl;
			}
			catch (std::exception& e) {
				std::cout << e.what() << std::endl;
			}
		}
		std::cout << std::endl;
		std::cout << UNDERLINE BLUE << "Only with negative numbers:" << NONE << std::endl;
		std::cout << std::endl;
		{
			Span	sp = Span(5);

			sp.addNumber(-8);
			sp.addNumber(-4978);
			sp.addNumber(-1541651);
			sp.addNumber(-54);
			sp.addNumber(-151);

			try {
				std::cout << "shortestSpan() = " << sp.shortestSpan() << std::endl;
				std::cout << "longestSpan() = " << sp.longestSpan() << std::endl;
			}
			catch (std::exception& e) {
				std::cout << e.what() << std::endl;
			}
		}
		std::cout << std::endl;
		std::cout << UNDERLINE BLUE << "With negative and positive numbers:" << NONE << std::endl;
		std::cout << std::endl;
		{
			Span	sp = Span(5);

			sp.addNumber(8);
			sp.addNumber(-4978);
			sp.addNumber(1541651);
			sp.addNumber(-54);
			sp.addNumber(151);

			try {
				std::cout << "shortestSpan() = " << sp.shortestSpan() << std::endl;
				std::cout << "longestSpan() = " << sp.longestSpan() << std::endl;
			}
			catch (std::exception& e) {
				std::cout << e.what() << std::endl;
			}
		}
		std::cout << std::endl;
		std::cout << UNDERLINE BLUE << "With negative and positive numbers:" << NONE << std::endl;
		std::cout << std::endl;
		{
			Span	sp = Span(5);

			sp.addNumber(-2147483648);
			sp.addNumber(-4978);
			sp.addNumber(2147483647);
			sp.addNumber(-54);
			sp.addNumber(151);

			try {
				std::cout << "shortestSpan() = " << sp.shortestSpan() << std::endl;
				std::cout << "longestSpan() = " << sp.longestSpan() << std::endl;
			}
			catch (std::exception& e) {
				std::cout << e.what() << std::endl;
			}
		}
	}
	return 0;
}