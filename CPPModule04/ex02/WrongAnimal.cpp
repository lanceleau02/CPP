/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:36:43 by laprieur          #+#    #+#             */
/*   Updated: 2023/09/26 11:26:25 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal") {
	std::cout << GREEN << "WrongAnimal class Default constructor called!" << NONE << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& source) {
	std::cout << GREEN << "WrongAnimal class Copy constructor called!" << NONE << std::endl;
	*this = source;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& source) {
	std::cout << GREEN << "WrongAnimal class Assignment operator called!" << NONE << std::endl;
	if (this != &source)
		_type = source._type;
	return *this;
}

WrongAnimal::~WrongAnimal() {
	std::cout << RED << "WrongAnimal class Default destructor called!" << NONE << std::endl;
}

void	WrongAnimal::makeSound(void) const {
	if (_type == "Dog")
		std::cout << BLUE << "Waf! Waf!" << NONE << std::endl;
	else if (_type == "Cat")
		std::cout << BLUE << "Meow!" << NONE << std::endl;
	else
		std::cout << BLUE << "Unknown sound" << NONE << std::endl;
}

std::string		WrongAnimal::getType(void) const {
	return _type;
}