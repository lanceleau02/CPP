/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 10:52:58 by laprieur          #+#    #+#             */
/*   Updated: 2023/09/12 13:30:35 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() :
	ClapTrap("ScavTrap", _maxHitPoints, _maxEnergyPoints, _maxAttackDamage) {
	std::cout << GREEN << "ScavTrap class Default constructor called!" << NONE << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) :
	ClapTrap(name, _maxHitPoints, _maxEnergyPoints, _maxAttackDamage) {
	std::cout << GREEN << "ScavTrap class String constructor called!" << NONE << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& source) : ClapTrap(source) {
	std::cout << GREEN << "ScavTrap class Copy constructor called!" << NONE << std::endl;
	*this = source;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& source) {
	std::cout << GREEN << "ScavTrap class Assignment operator called!" << NONE << std::endl;
	_name = source._name;
	_hitPoints = source._hitPoints;
	_energyPoints = source._energyPoints;
	_attackDamage = source._attackDamage;
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << RED << "ScavTrap class Default destructor called!" << NONE << std::endl;
}

void	ScavTrap::attack(const std::string& target) {
	if (verifyHitAndEnergyPoints() == false)
		return ;
	_energyPoints--;
	std::cout
		<< "ScavTrap " << BLUE << _name << NONE << " attacks "
		<< RED << target << NONE << ", causing "
		<< RED << _attackDamage << NONE << " points of damage and loses "
		<< RED << "1" << NONE << " energy point!" << std::endl;
}

void	ScavTrap::guardGate() {
	std::cout << BLUE << "ScavTrap " << _name << " is now in Gate keeper mode." << NONE << std::endl;
}