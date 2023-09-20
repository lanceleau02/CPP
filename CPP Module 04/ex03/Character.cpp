/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 10:20:18 by laprieur          #+#    #+#             */
/*   Updated: 2023/09/20 16:46:00 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name("Unknown") {
	std::cout << GREEN << "Character class Default constructor called!" << NONE << std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(const std::string& name) : _name(name) {
	std::cout << GREEN << "Character class Name constructor called!" << NONE << std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(const Character& source) {
	std::cout << GREEN << "Character class Copy constructor called!" << NONE << std::endl;
	*this = source;
}

Character&	Character::operator=(const Character& source) {
	std::cout << GREEN << "Character class Assignment operator called!" << NONE << std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = source._inventory[i];
	_name = source._name;
	return *this;
}

Character::~Character() {
	std::cout << RED << "Character class Default destructor called!" << NONE << std::endl;
	for (int i = 0; i < 4; i++)
		if (_inventory[i] != NULL)
			delete _inventory[i];
}

std::string const&	Character::getName() const {
	return _name;
}

void	Character::equip(AMateria* m) {
	for (int i = 0; i < 4; i++) {
		if (_inventory[i] == NULL) {
			_inventory[i] = m;
			std::cout << BLUE << "Character " << _name << " equips the Materia at slot " << i << "!" << NONE << std::endl;
			return ;
		}
	}
	std::cout << RED << "Character " << _name << " cannot equip this Materia!" << NONE << std::endl;
	delete m;
}

void	Character::unequip(int idx) {
	if (idx < 4 && _inventory[idx] != NULL) {
		_inventory[idx] = NULL;
		std::cout << BLUE << "Character " << _name << " unequips the Materia at slot " << idx << "!" << NONE << std::endl;
	}
	else
		std::cout << RED << "Character " << _name << " cannot unequip this Materia!" << NONE << std::endl;
}

void	Character::use(int idx, ICharacter& target) {
	if (idx < 4 && _inventory[idx] != NULL) {
		_inventory[idx]->use(target);
		std::cout << BLUE << "Character " << _name << " use " << _inventory[idx]->getType() << " on " << target.getName() << NONE << std::endl;
	}
	else
		std::cout << RED << "Character " << _name << " cannot use this type of Materia on " << target.getName() << NONE << std::endl;
}