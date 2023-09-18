/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 10:55:00 by laprieur          #+#    #+#             */
/*   Updated: 2023/09/18 11:43:19 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	std::cout << GREEN << "MateriaSource class Default constructor called!" << NONE << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& source) {
	std::cout << GREEN << "MateriaSource class Copy constructor called!" << NONE << std::endl;
	*this = source;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& source) {
	std::cout << GREEN << "MateriaSource class Assignment operator called!" << NONE << std::endl;
	return *this;
}

MateriaSource::~MateriaSource() {
	std::cout << GREEN << "MateriaSource class Default destructor called!" << NONE << std::endl;
}

void MateriaSource::learnMateria(AMateria*) {

}

AMateria* MateriaSource::createMateria(std::string const& type) {
	
}