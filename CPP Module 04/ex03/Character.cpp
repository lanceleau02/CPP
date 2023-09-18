/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 10:20:18 by laprieur          #+#    #+#             */
/*   Updated: 2023/09/18 11:09:50 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name("Unknown") {
	std::cout << GREEN << "Character class Default constructor called!" << NONE << std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(const std::string& name) _name(name) {
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
	std::cout << GREEN << "Character class Default destructor called!" << NONE << std::endl;
}

std::string const&	getName() const {
	return _name;
}

void	equip(AMateria* m) {

}

void	unequip(int idx) {

}

void	use(int idx, ICharacter& target) {
	
}