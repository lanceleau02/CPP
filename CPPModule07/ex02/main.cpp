/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 09:23:21 by laprieur          #+#    #+#             */
/*   Updated: 2023/10/31 09:53:26 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "Array.hpp"

#define MAX_VAL 750

#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define NONE	"\033[0m"

int main(int, char**)
{
	std::cout << YELLOW << "+--------+ MAIN TESTS +--------+" << NONE << std::endl;
	std::cout << std::endl;
	{
		Array<int> numbers(MAX_VAL);
		int* mirror = new int[MAX_VAL];
		srand(time(NULL));
		for (int i = 0; i < MAX_VAL; i++) {
			const int value = rand();
			numbers[i] = value;
			mirror[i] = value;
		}

		{
			Array<int> tmp = numbers;
			Array<int> test(tmp);
		}
		
		for (int i = 0; i < MAX_VAL; i++) {
			if (mirror[i] != numbers[i]) {
				std::cerr << "didn't save the same value!!" << std::endl;
				return 1;
			}
		}
		try {
			numbers[-2] = 0;
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << '\n';
		}
		try {
			numbers[MAX_VAL] = 0;
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << '\n';
		}

		for (int i = 0; i < MAX_VAL; i++) {
			numbers[i] = rand();
		}
		delete [] mirror;
	}
	std::cout << std::endl;
	std::cout << YELLOW << "+--------+ SUBJECT TEST +--------+" << NONE << std::endl;
	std::cout << std::endl;
	{
		int*	a = new int();
		
		std::cout << *a << std::endl;
		delete a;
	}
	std::cout << std::endl;
	std::cout << YELLOW << "+--------+ DEEP COPY TEST +--------+" << NONE << std::endl;
	std::cout << std::endl;
	{
		Array<int>	arr1(10);
		Array<int>	arr2(10);
		
		std::cout << "Here are the values in the array arr1: ";
		for (unsigned int i = 0; i < arr1.size(); i++) {
			arr1[i] = i;
			std::cout << arr1[i];
		}
		
		std::cout << std::endl;
		std::cout << std::endl << "Here are the values in the array arr2: ";
		for (unsigned int i = 0; i < arr2.size(); i++)
			std::cout << arr2[i];

		std::cout << std::endl << std::endl << "Now we do the deep copy: arr2 = arr1" << std::endl << std::endl;
		
		arr2 = arr1;
		
		std::cout << "Here are the values in the array arr1 after the deep copy: ";
		for (unsigned int i = 0; i < arr1.size(); i++)
			std::cout << arr1[i];
		std::cout << std::endl;
			
		std::cout << std::endl << "Here are the values in the array arr2 after the deep copy: ";
		for (unsigned int i = 0; i < arr2.size(); i++)
			std::cout << arr2[i];
		std::cout << std::endl;
		
		std::cout << std::endl << "Now we set arr2[5] = 8" << std::endl << std::endl;

		arr2[5] = 8;
		
		std::cout << "Here are the values in the array arr1: ";
		for (unsigned int i = 0; i < arr1.size(); i++)
			std::cout << arr1[i];
		std::cout << std::endl;
			
		std::cout << std::endl << "Here are the values in the array arr2: ";
		for (unsigned int i = 0; i < arr2.size(); i++)
			std::cout << arr2[i];
		std::cout << std::endl;
	}
	return 0;
}