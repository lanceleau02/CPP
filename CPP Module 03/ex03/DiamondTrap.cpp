/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:51:05 by laprieur          #+#    #+#             */
/*   Updated: 2023/09/06 15:51:58 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ScavTrap(), FragTrap() {
	ClapTrap(_name, _maxHitPoints, _maxEnergyPoints, _maxAttackDamage);
	std::cout << GREEN << "DiamondTrap class Default constructor called!" << NONE << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name) : ScavTrap(name), FragTrap(name) {
	_name = name;
	//ClapTrap::_name = name + "_clap_name";
	//ClapTrap(_name, _maxHitPoints, _maxEnergyPoints, _maxAttackDamage);
	std::cout << GREEN << "DiamondTrap class String constructor called!" << NONE << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& source) : ScavTrap(source._name), FragTrap(source._name) {
	*this = source;
	std::cout << GREEN << "DiamondTrap class Copy constructor called!" << NONE << std::endl;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& source) {
	if (this == &source)
		return *this;
	std::cout << GREEN << "DiamondTrap class Assignment operator called!" << NONE << std::endl;
	return *this;
}

DiamondTrap::~DiamondTrap() {
	std::cout << RED << "DiamondTrap class Default destructor called!" << NONE << std::endl;
}

void	DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI() {
	//std::cout << BLUE << "Hello! I'm " << _name << "! Also known as " << ClapTrap::_name << "." << NONE << std::endl;
}
