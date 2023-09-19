/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:52:32 by laprieur          #+#    #+#             */
/*   Updated: 2023/09/19 15:36:00 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
	std::cout << GREEN << "Ice class Default constructor called!" << NONE << std::endl;
}

Ice::Ice(const Ice& source) : AMateria(source) {
	std::cout << GREEN << "Ice class Copy constructor called!" << NONE << std::endl;
	*this = source;
}

Ice&	Ice::operator=(const Ice& source) {
	std::cout << GREEN << "Ice class Assignment operator called!" << NONE << std::endl;
	_type = source._type;
	return *this;
}

Ice::~Ice() {
	std::cout << GREEN << "Ice class Default destructor called!" << NONE << std::endl;
}

AMateria*	Ice::clone() const {
	AMateria*	clone = new Ice();
	return clone;
}

void	Ice::use(ICharacter& target) {
	std::cout << BLUE << "* shoots an ice bolt at " << target.getName() << " *" << NONE << std::endl; 
}