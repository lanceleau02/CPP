/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:54:42 by laprieur          #+#    #+#             */
/*   Updated: 2023/10/31 17:16:03 by laprieur         ###   ########.fr       */
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
			Span	sp = Span(0);

			try {
				std::cout << sp.shortestSpan() << std::endl;
			}
			catch (std::exception& e) {
				std::cerr << e.what() << std::endl;
			}
		}
		std::cout << std::endl;
		std::cout << UNDERLINE BLUE << "Not enough numbers stored:" << NONE << std::endl;
		std::cout << std::endl;
		{
			Span	sp = Span(1);

			sp.addNumber(5);

			try {
				std::cout << sp.shortestSpan() << std::endl;
			}
			catch (std::exception& e) {
				std::cerr << e.what() << std::endl;
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
				std::cerr << e.what() << std::endl;
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
				std::cerr << e.what() << std::endl;
			}
		}
		std::cout << std::endl;
		std::cout << UNDERLINE BLUE << "Only with positive numbers:" << NONE << std::endl;
		std::cout << std::endl;
		{
			Span	sp = Span(5);

			sp.addNumber(8);
			sp.addNumber(4978);
			sp.addNumber(1541651);
			sp.addNumber(54);
			sp.addNumber(151);

			try {
				std::cout << "shortestSpan() = " << sp.shortestSpan() << std::endl;
				std::cout << "longestSpan() = " << sp.longestSpan() << std::endl;
			}
			catch (std::exception& e) {
				std::cerr << e.what() << std::endl;
			}
		}
		std::cout << std::endl;
		std::cout << UNDERLINE BLUE << "With MIN_INT and MAX_INT:" << NONE << std::endl;
		std::cout << std::endl;
		{
			Span	sp = Span(2);

			sp.addNumber(-2147483648);
			sp.addNumber(2147483647);

			try {
				std::cout << "shortestSpan() = " << sp.shortestSpan() << std::endl;
				std::cout << "longestSpan() = " << sp.longestSpan() << std::endl;
			}
			catch (std::exception& e) {
				std::cerr << e.what() << std::endl;
			}
		}
	}
	std::cout << std::endl;
	std::cout << YELLOW << "+--------+ addNumbers() FUNCTION TESTS +--------+" << NONE << std::endl;
	std::cout << std::endl;
	{
		std::cout << UNDERLINE BLUE << "Too many elements to add (span size = 10):" << NONE << std::endl;
		std::cout << std::endl;
		{
			Span				sp(10);
			int					array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
			std::vector<int>	nb1(array, array + 5);
			std::vector<int>	nb2(array, array + 6);

			try {
				std::cout << "First, we add 5 numbers to the vector." << std::endl << std::endl;
				sp.addNumbers(nb1.begin(), nb1.end());
				std::cout << "And then, we try to add 6 more numbers to the vector." << std::endl << std::endl;
				sp.addNumbers(nb2.begin(), nb2.end());
			}
			catch (std::exception& e) {
				std::cerr << e.what() << std::endl;
			}
		}
		std::cout << std::endl;
		std::cout << UNDERLINE BLUE << "Minimum test with 10 000 numbers:" << NONE << std::endl;
		std::cout << std::endl;
		{
			Span				sp(10000);
			int					array[10000];
			for (size_t i = 0; i < 10000; i++)
				array[i] = i;
			std::vector<int>	nb(array, array + 10000);

			try {
				sp.addNumbers(nb.begin(), nb.end());
				std::cout << "shortestSpan() = " << sp.shortestSpan() << std::endl;
				std::cout << "longestSpan() = " << sp.longestSpan() << std::endl;
			}
			catch (std::exception& e) {
				std::cerr << e.what() << std::endl;
			}
		}
		std::cout << std::endl;
		std::cout << UNDERLINE BLUE << "More than 10 000 numbers:" << NONE << std::endl;
		std::cout << std::endl;
		{
			Span				sp(15000);
			int					array[15000];
			for (size_t i = 0; i < 15000; i++)
				array[i] = i;
			std::vector<int>	nb(array, array + 15000);

			try {
				sp.addNumbers(nb.begin(), nb.end());
				std::cout << "shortestSpan() = " << sp.shortestSpan() << std::endl;
				std::cout << "longestSpan() = " << sp.longestSpan() << std::endl;
			}
			catch (std::exception& e) {
				std::cerr << e.what() << std::endl;
			}
		}
	}
	std::cout << std::endl;
	std::cout << YELLOW << "+--------+ DEEP COPY TEST +--------+" << NONE << std::endl;
	std::cout << std::endl;
	{
		Span	sp1(5);
		Span	sp2(5);
		
		try {
			sp1.addNumber(6);
			sp1.addNumber(3);
			sp1.addNumber(17);
			sp1.addNumber(9);
			sp1.addNumber(11);
		}
		catch (std::exception& e) {
				std::cerr << e.what() << std::endl;
		}

		std::cout << "Values before deep copy:" << std::endl << std::endl;
		try {
			std::cout << "sp1 = ";
			for (size_t i = 0; i < 5; i++)
				std::cout << sp1.getNumber(i) << " ";
			std::cout << std::endl;
			std::cout << "sp2 = ";
			for (size_t i = 0; i < 5; i++)
				std::cout << sp2.getNumber(i) << " ";
		}
		catch (std::exception& e) {
				std::cerr << e.what() << std::endl;
		}
		
		sp2 = sp1;
		std::cout << std::endl << "Values after deep copy:" << std::endl << std::endl;
		try {
			std::cout << "sp1 = ";
			for (size_t i = 0; i < 5; i++)
				std::cout << sp1.getNumber(i) << " ";
			std::cout << std::endl;
			std::cout << "sp2 = ";
			for (size_t i = 0; i < 5; i++)
				std::cout << sp2.getNumber(i) << " ";
		}
		catch (std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
		
		std::cout << std::endl << std::endl << "Now we modify the last vector number: sp2._numbers[4] = 50" << std::endl << std::endl;
		try {
			sp2.setNumber(4, 50);
			
			std::cout << "Values after modification:" << std::endl << std::endl;

			std::cout << "sp1 = ";
			for (size_t i = 0; i < 5; i++)
				std::cout << sp1.getNumber(i) << " ";
			std::cout << std::endl;
			std::cout << "sp2 = ";
			for (size_t i = 0; i < 5; i++)
				std::cout << sp2.getNumber(i) << " ";
			std::cout << std::endl;
		}
		catch (std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}
	return 0;
}