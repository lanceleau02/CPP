/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:36:43 by laprieur          #+#    #+#             */
/*   Updated: 2023/09/14 11:46:14 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("AAnimal") {
	std::cout << GREEN << "AAnimal class Default constructor called!" << NONE << std::endl;
}

AAnimal::AAnimal(const AAnimal& source) {
	std::cout << GREEN << "AAnimal class Copy constructor called!" << NONE << std::endl;
	*this = source;
}

AAnimal&	AAnimal::operator=(const AAnimal& source) {
	std::cout << GREEN << "AAnimal class Assignment operator called!" << NONE << std::endl;
	_type = source._type;
	return *this;
}

AAnimal::~AAnimal() {
	std::cout << RED << "AAnimal class Default destructor called!" << NONE << std::endl;
}

void	AAnimal::makeSound(void) const {
	if (_type == "Dog")
		std::cout << BLUE << "Waf! Waf!" << NONE << std::endl;
	else if (_type == "Cat")
		std::cout << BLUE << "Meow!" << NONE << std::endl;
	else
		std::cout << BLUE << "Unknown sound" << NONE << std::endl;
}

std::string		AAnimal::getType(void) const {
	return _type;
}