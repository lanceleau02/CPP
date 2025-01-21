/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:09:54 by laprieur          #+#    #+#             */
/*   Updated: 2023/09/21 11:36:53 by laprieur         ###   ########.fr       */
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
		const int	ideaNumber = 10;

		std::cout << std::endl;
		Einstein.getBrain()->setIdea(ideaNumber, "1.21 Gigawatts!?");
		std::cout << BLUE << "Here's the Beethoven's idea number " << ideaNumber << ": " << NONE << Beethoven.getBrain()->getIdea(ideaNumber) << std::endl;
		std::cout << BLUE << "Here's the Einstein's idea number " << ideaNumber << ": " << NONE << Einstein.getBrain()->getIdea(ideaNumber) << std::endl;
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout << YELLOW << "+--------+ CAT CLASS DEEP COPY TEST +--------+" << NONE << std::endl;
	std::cout << std::endl;
	{
		Cat	Felix;
		Cat	Garfield = Felix;
		const int	ideaNumber = 10;

		std::cout << std::endl;
		Garfield.getBrain()->setIdea(ideaNumber, "Lasagna!");
		std::cout << BLUE << "Here's the Felix's idea number " << ideaNumber << ": " << NONE << Felix.getBrain()->getIdea(ideaNumber) << std::endl;
		std::cout << BLUE << "Here's the Garfield's idea number " << ideaNumber << ": " << NONE << Garfield.getBrain()->getIdea(ideaNumber) << std::endl;
		std::cout << std::endl;
	}
	return 0;
}