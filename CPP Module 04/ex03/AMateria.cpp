/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:05:03 by laprieur          #+#    #+#             */
/*   Updated: 2023/09/15 14:47:31 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : _type("Undefined") {
	std::cout << GREEN << "AMateria class Default constructor called!" << NONE << std::endl;
}

AMateria::AMateria(std::string const& type) : _type(type) {
	std::cout << GREEN << "AMateria class Type constructor called!" << NONE << std::endl;
}

AMateria::AMateria(const AMateria& source) {
	std::cout << GREEN << "AMateria class Copy constructor called!" << NONE << std::endl;
	*this = source;
}

AMateria&	AMateria::operator=(const AMateria& source) {
	std::cout << GREEN << "AMateria class Assignment operator called!" << NONE << std::endl;
	_type = source._type;
	return *this;
}

AMateria::~AMateria() {
	std::cout << GREEN << "AMateria class Default destructor called!" << NONE << std::endl;
}

std::string const&	AMateria::getType() const {
	return _type;
}

AMateria*	AMateria::clone() const {
	AMateria*	clone = new AMateria();
	return clone;
}

void		AMateria::use(ICharacter& target) {
	std::cout << "AMateria " << _type << " used on " << target << "!" << std::endl;
}