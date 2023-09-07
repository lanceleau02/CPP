/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:51:05 by laprieur          #+#    #+#             */
/*   Updated: 2023/09/07 13:53:46 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() :
	ClapTrap("DiamondTrap_clap_name", FragTrap::_maxHitPoints, ScavTrap::_maxEnergyPoints, FragTrap::_maxAttackDamage), ScavTrap(), FragTrap(), _name("DiamondTrap") {
	std::cout << GREEN << "DiamondTrap class Default constructor called!" << NONE << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name) :
	ClapTrap(name + "_clap_name", FragTrap::_maxHitPoints, ScavTrap::_maxEnergyPoints, FragTrap::_maxAttackDamage), ScavTrap(name), FragTrap(name), _name(name) {
	std::cout << GREEN << "DiamondTrap class String constructor called!" << NONE << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& source) {
	*this = source;
	std::cout << GREEN << "DiamondTrap class Copy constructor called!" << NONE << std::endl;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& source) {
	_name = source._name;
	_hitPoints = source._hitPoints;
	_energyPoints = source._energyPoints;
	_attackDamage = source._attackDamage;
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
	std::cout << BLUE << "Hello! I'm " << _name << "! Also known as " << ClapTrap::_name << "." << NONE << std::endl;
}
