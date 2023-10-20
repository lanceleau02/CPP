/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:54:42 by laprieur          #+#    #+#             */
/*   Updated: 2023/10/20 16:52:45 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <string>
#include <cstddef>
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
	std::cout << YELLOW << "+--------+ SEQUENCE CONTAINERS +--------+" << NONE << std::endl;
	std::cout << std::endl;
	{
		int	toFind = 3;
		int	toNotFind = 6;
		int	arr[] = {1, 2, 3, 4, 5};

		std::cout << "For these tests, toFind = " << toFind << " and toNotFind = " << toNotFind << "." << std::endl << std::endl;		
		std::cout << UNDERLINE BLUE << "std::vector" << NONE << std::endl << std::endl;
		{
			std::vector<int>	v(arr, arr + sizeof(arr) / sizeof(arr[0]));
			size_t				ret1 = easyfind(v, toFind);
			size_t				ret2 = easyfind(v, toNotFind);
	
			if (ret1 != std::string::npos)
				std::cout << GREEN << "Element toFind found!" << NONE << std::endl;
			else 
				std::cout << RED << "Element toFind not found!" << NONE << std::endl;
			if (ret2 != std::string::npos)
				std::cout << GREEN << "Element toNotFind found!" << NONE << std::endl;
			else 
				std::cout << RED << "Element toNotFind not found!" << NONE << std::endl;
		}
		/* std::cout << std::endl;
		std::cout << UNDERLINE BLUE << "std::deque" << NONE << std::endl << std::endl;
		{
			std::deque<int>		d(arr, arr + sizeof(arr) / sizeof(arr[0]));

			if (*easyfind(d, toFind) == toFind)
				std::cout << GREEN << "Element toFind found!" << NONE << std::endl;
			else 
				std::cout << RED << "Element toFind not found!" << NONE << std::endl;
			if (*easyfind(d, toNotFind) == toNotFind)
				std::cout << GREEN << "Element toNotFind found!" << NONE << std::endl;
			else 
				std::cout << RED << "Element toNotFind not found!" << NONE << std::endl;
		}
		std::cout << std::endl;
		std::cout << UNDERLINE BLUE << "std::list" << NONE << std::endl << std::endl;
		{
			std::list<int>	l(arr, arr + sizeof(arr) / sizeof(arr[0]));

			if (*easyfind(l, toFind) == toFind)
				std::cout << GREEN << "Element toFind found!" << NONE << std::endl;
			else 
				std::cout << RED << "Element toFind not found!" << NONE << std::endl;
			if (*easyfind(l, toNotFind) == toNotFind)
				std::cout << GREEN << "Element toNotFind found!" << NONE << std::endl;
			else 
				std::cout << RED << "Element toNotFind not found!" << NONE << std::endl;
		} */
	}
	return 0;
}