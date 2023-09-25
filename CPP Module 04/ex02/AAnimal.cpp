/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:36:43 by laprieur          #+#    #+#             */
/*   Updated: 2023/09/25 16:37:36 by laprieur         ###   ########.fr       */
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

std::string		AAnimal::getType(void) const {
	return _type;
}