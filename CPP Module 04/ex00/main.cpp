/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:09:54 by laprieur          #+#    #+#             */
/*   Updated: 2023/09/12 11:38:09 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main() {
	std::cout << YELLOW << "+--------+ ANIMAL CLASS TESTS +--------+" << NONE << std::endl;
	std::cout << std::endl;
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		
		std::cout << meta->getType() << " " << std::endl;
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();

		delete meta;
		delete j;
		delete i;
	}
	std::cout << std::endl;
	std::cout << YELLOW << "+--------+ WRONG ANIMAL CLASS TESTS +--------+" << NONE << std::endl;
	std::cout << std::endl;
	{
		const WrongAnimal* i = new WrongCat();
		
		std::cout << i->getType() << " " << std::endl;
		
		i->makeSound();

		delete i;
	}
	return 0;
}