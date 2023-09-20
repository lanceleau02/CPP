/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:18:30 by laprieur          #+#    #+#             */
/*   Updated: 2023/09/20 09:07:37 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
	std::cout << GREEN << "Cure class Default constructor called!" << NONE << std::endl;
}

Cure::Cure(const Cure& source) : AMateria(source) {
	std::cout << GREEN << "Cure class Copy constructor called!" << NONE << std::endl;
	*this = source;
}

Cure&	Cure::operator=(const Cure& source) {
	std::cout << GREEN << "Cure class Assignment operator called!" << NONE << std::endl;
	_type = source._type;
	return *this;
}

Cure::~Cure() {
	std::cout << RED << "Cure class Default destructor called!" << NONE << std::endl;
}

AMateria*	Cure::clone() const {
	AMateria*	clone = new Cure();
	return clone;
}

void	Cure::use(ICharacter& target) {
	std::cout << BLUE << "* heals " << target.getName() << "'s wounds *" << NONE << std::endl;
}