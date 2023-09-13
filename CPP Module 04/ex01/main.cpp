/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:09:54 by laprieur          #+#    #+#             */
/*   Updated: 2023/09/13 16:49:45 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main() {
	std::cout << YELLOW << "+--------+ MAIN TESTS +--------+" << NONE << std::endl;
	std::cout << std::endl;
	{
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		
		delete j; //should not create a leak
		delete i;
	}
	std::cout << std::endl;
	std::cout << YELLOW << "+--------+ ARRAY TEST +--------+" << NONE << std::endl;
	std::cout << std::endl;
	{
		Animal*	animals[10];

		std::cout << "Let's create all the animals!" << std::endl << std::endl;
		for (int i = 0; i < 10; i++) {
			if (i % 2 == 0)
				animals[i] = new Dog();
			else
				animals[i] = new Cat();
		}
		std::cout << std::endl;
		std::cout << "Here's a simple loop to show you animals are correctly created:" << std::endl << std::endl;
		for (int i = 0; i < 10; i++)
			animals[i]->makeSound();
		std::cout << std::endl;
		std::cout << "Now, let's delete all these animals!" << std::endl << std::endl;
		for (int i = 0; i < 10; i++)
			delete animals[i];
	}
	std::cout << std::endl;
	std::cout << YELLOW << "+--------+ DOG CLASS DEEP COPY TEST +--------+" << NONE << std::endl;
	std::cout << std::endl;
	{
		Dog	Beethoven;
		
		Dog	Einstein = Beethoven;

		Einstein = Dog();
		
		Beethoven.makeSound();
		Einstein.getBrain()->setIdea(10, "test");
		std::cout << Beethoven.getBrain()->getIdea(10) << std::endl;
		std::cout << Einstein.getBrain()->getIdea(10) << std::endl;
	}
	return 0;
}