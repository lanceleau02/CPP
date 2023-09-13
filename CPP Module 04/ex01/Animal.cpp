/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:36:43 by laprieur          #+#    #+#             */
/*   Updated: 2023/09/12 09:08:03 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Animal") {
	std::cout << GREEN << "Animal class Default constructor called!" << NONE << std::endl;
}

Animal::Animal(const Animal& source) {
	std::cout << GREEN << "Animal class Copy constructor called!" << NONE << std::endl;
	*this = source;
}

Animal&	Animal::operator=(const Animal& source) {
	std::cout << GREEN << "Animal class Assignment operator called!" << NONE << std::endl;
	_type = source._type;
	return *this;
}

Animal::~Animal() {
	std::cout << RED << "Animal class Default destructor called!" << NONE << std::endl;
}

void	Animal::makeSound(void) const {
	if (_type == "Dog")
		std::cout << BLUE << "Waf! Waf!" << NONE << std::endl;
	else if (_type == "Cat")
		std::cout << BLUE << "Meow!" << NONE << std::endl;
	else
		std::cout << BLUE << "Unknown sound" << NONE << std::endl;
}

std::string		Animal::getType(void) const {
	return _type;
}