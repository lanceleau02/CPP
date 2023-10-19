/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:01:37 by laprieur          #+#    #+#             */
/*   Updated: 2023/10/19 11:28:02 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define NONE	"\033[0m"

Base*	generate(void) {
	switch (std::rand() % 3) {
		case 0:
			return (new A);
		case 1:
			return (new B);
		default:
			return (new C);
	}
}

void	identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void	identify(Base& p) {
	try {
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
	}
	catch (const std::exception& e) {}
	try { 
		B& b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "B" << std::endl;
	}
	catch (const std::exception& e) {}
	try {
		C& c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "C" << std::endl;
	}
	catch (const std::exception& e) {}
}

int	main(void) {
	std::srand(std::time(NULL));
	
	Base*	obj1 = generate();
	Base*	obj2 = generate();
	Base*	obj3 = generate();
	Base*	obj4 = new Base();
	
	std::cout << YELLOW << "+--------+ identify(*) FUNCTION TESTS +--------+" << NONE << std::endl;
	std::cout << std::endl;
	{
		std::cout << BLUE << "The type of obj1 is: " << NONE;
		identify(obj1);
		std::cout << BLUE << "The type of obj2 is: " << NONE;
		identify(obj2);
		std::cout << BLUE << "The type of obj3 is: " << NONE;
		identify(obj3);
		std::cout << BLUE << "The type of obj4 is: " << NONE;
		identify(obj4);
	}
	std::cout << std::endl << std::endl;
	std::cout << YELLOW << "+--------+ identify(&) FUNCTION TESTS +--------+" << NONE << std::endl;
	std::cout << std::endl;
	{
		std::cout << BLUE << "The type of obj1 is: " << NONE;
		identify(*obj1);
		std::cout << BLUE << "The type of obj2 is: " << NONE;
		identify(*obj2);
		std::cout << BLUE << "The type of obj3 is: " << NONE;
		identify(*obj3);
		std::cout << BLUE << "The type of obj4 is: " << NONE;
		identify(*obj4);
	}
	std::cout << std::endl;
}