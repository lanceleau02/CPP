/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 10:55:00 by laprieur          #+#    #+#             */
/*   Updated: 2023/09/19 15:48:34 by laprieur         ###   ########.fr       */
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
	for (int i = 0; i < 4; i++)
		_materias[i] = source._materias[i];
	return *this;
}

MateriaSource::~MateriaSource() {
	std::cout << GREEN << "MateriaSource class Default destructor called!" << NONE << std::endl;
}

bool	MateriaSource::verifyFullInventory() const {
	for (int i = 0; i < 4; i++) {
		if (_materias[i] == NULL)
			return false;
	}
	return true;
}

void MateriaSource::learnMateria(AMateria* m) {
	for (int i = 0; i < 4; i++) {
		if (_materias[i] == NULL && !verifyFullInventory()) {
			_materias[i] = m;
			std::cout << GREEN << "Materia " << m->getType() << " learned and stored at slot " << i << "!" << NONE << std::endl;
		}
		else
			std::cout << RED << "Materia " << m->getType() << " cannot be learned!" << NONE << std::endl;
	}
}

AMateria* MateriaSource::createMateria(std::string const& type) {
	for (int i = 0; i < 4; i++)
		if (_materias[i] != NULL && _materias[i]->getType() == type)
			return (_materias[i]->clone());
	return NULL;
}