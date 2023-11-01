/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:54:42 by laprieur          #+#    #+#             */
/*   Updated: 2023/11/01 14:16:48 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <list>

#define UNDERLINE "\033[4m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define NONE	"\033[0m"

int	main(void) {
	{		
		int	toFind = 3;
		int	toNotFind = 6;
		int	array[] = {1, 2, 3, 4, 5};

		std::cout << std::endl << YELLOW << "For all these tests, toFind = " << toFind << " and toNotFind = " << toNotFind << "." << NONE << std::endl << std::endl;
		
		std::cout << UNDERLINE BLUE << "std::vector" << NONE << std::endl << std::endl;
		{
			std::vector<int>			v(array, array + 5);
			std::vector<int>::iterator	it1 = easyfind(v, toFind);
			std::vector<int>::iterator	it2 = easyfind(v, toNotFind);
	
			if (it1 != v.end())
				std::cout << GREEN << "Element toFind found!" << NONE << std::endl;
			else 
				std::cout << RED << "Element toFind not found!" << NONE << std::endl;
			if (it2 != v.end())
				std::cout << GREEN << "Element toNotFind found!" << NONE << std::endl;
			else 
				std::cout << RED << "Element toNotFind not found!" << NONE << std::endl;
		}
		std::cout << std::endl;
		std::cout << UNDERLINE BLUE << "std::deque" << NONE << std::endl << std::endl;
		{
			std::deque<int>				d(array, array + 5);
			std::deque<int>::iterator	it1 = easyfind(d, toFind);
			std::deque<int>::iterator	it2 = easyfind(d, toNotFind);

			if (it1 != d.end())
				std::cout << GREEN << "Element toFind found!" << NONE << std::endl;
			else 
				std::cout << RED << "Element toFind not found!" << NONE << std::endl;
			if (it2 != d.end())
				std::cout << GREEN << "Element toNotFind found!" << NONE << std::endl;
			else 
				std::cout << RED << "Element toNotFind not found!" << NONE << std::endl;
		}
		std::cout << std::endl;
		std::cout << UNDERLINE BLUE << "std::list" << NONE << std::endl << std::endl;
		{
			std::list<int>				l(array, array + 5);
			std::list<int>::iterator	it1 = easyfind(l, toFind);
			std::list<int>::iterator	it2 = easyfind(l, toNotFind);

			if (it1 != l.end())
				std::cout << GREEN << "Element toFind found!" << NONE << std::endl;
			else 
				std::cout << RED << "Element toFind not found!" << NONE << std::endl;
			if (it2 != l.end())
				std::cout << GREEN << "Element toNotFind found!" << NONE << std::endl;
			else 
				std::cout << RED << "Element toNotFind not found!" << NONE << std::endl;
		}
	}
	return 0;
}