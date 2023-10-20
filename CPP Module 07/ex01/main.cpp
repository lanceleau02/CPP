/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:21:07 by laprieur          #+#    #+#             */
/*   Updated: 2023/10/20 09:34:42 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define NONE	"\033[0m"

int	main(void) {
	std::cout << YELLOW << "+--------+ INT ARRAY TEST +--------+" << NONE << std::endl;
	std::cout << std::endl;
	{
		int	array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	
		iter(array, 10, &print);
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout << YELLOW << "+--------+ CHAR ARRAY TEST +--------+" << NONE << std::endl;
	std::cout << std::endl;
	{
		char	array[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
	
		iter(array, 10, &print);
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout << YELLOW << "+--------+ STRING ARRAY TEST +--------+" << NONE << std::endl;
	std::cout << std::endl;
	{
		std::string	array[2] = {"Forty", "Two"};
	
		iter(array, 2, &print);
		std::cout << std::endl;
	}
}