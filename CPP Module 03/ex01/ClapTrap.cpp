/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:41:27 by laprieur          #+#    #+#             */
/*   Updated: 2023/09/12 13:11:07 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() :
	_name("ClapTrap"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << GREEN << "ClapTrap class Default constructor called!" << NONE << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) :
	_name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << GREEN << "ClapTrap class String constructor called!" << NONE << std::endl;
}

ClapTrap::ClapTrap(std::string name, unsigned int hitPoints, unsigned int energyPoints, unsigned int attackDamage) :
	_name(name), _hitPoints(hitPoints), _energyPoints(energyPoints), _attackDamage(attackDamage) {
	std::cout << GREEN << "ClapTrap class Assignment constructor called!" << NONE << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& source) {
	std::cout << GREEN << "ClapTrap class Copy constructor called!" << NONE << std::endl;
	*this = source;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& source) {
	std::cout << GREEN << "ClapTrap class Assignment operator called!" << NONE << std::endl;
	_name = source._name;
	_hitPoints = source._hitPoints;
	_energyPoints = source._energyPoints;
	_attackDamage = source._attackDamage;
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << RED << "ClapTrap class Default destructor called!" << NONE << std::endl;
}

void	ClapTrap::printStats() {
	std::cout << std::endl;
	std::cout
		<< BLUE << _name << ":" << NONE << std::endl
		<< "Hit points: " << BLUE << _hitPoints << NONE << std::endl
		<< "Energy points: " << BLUE << _energyPoints << NONE << std::endl
		<< "Attack damage: " << BLUE << _attackDamage << NONE << std::endl;
}

bool	ClapTrap::verifyHitAndEnergyPoints() {
	if (_hitPoints <= 0)
		std::cout << RED << "Impossible! " << _name
		<< " has no more hit points!" << NONE << std::endl;
	else if (_energyPoints <= 0)
		std::cout << RED << "Impossible! " << _name
		<< " has no more energy points!" << NONE << std::endl;
	else
		return true;
	return false;
}

void	ClapTrap::attack(const std::string& target) {
	if (verifyHitAndEnergyPoints() == false)
		return ;
	_energyPoints--;
	std::cout
		<< "ClapTrap " << BLUE << _name << NONE << " attacks "
		<< RED << target << NONE << ", causing "
		<< RED << _attackDamage << NONE << " points of damage and loses "
		<< RED << "1" << NONE << " energy point!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (verifyHitAndEnergyPoints() == false)
		return ;
	if (_hitPoints <= amount)
		_hitPoints = 0;
	else
		_hitPoints -= amount;
	std::cout
		<< "ClapTrap " << BLUE << _name << NONE << " gets "
		<< RED << amount << NONE
		<< " points of damage!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (verifyHitAndEnergyPoints() == false)
		return ;
	_hitPoints += amount;
	_energyPoints--;
	std::cout
		<< "ClapTrap " << BLUE << _name << NONE << " repairs itself, gets "
		<< GREEN << amount << NONE << " hit points back and loses " << RED "1"
		<< NONE << " energy point!" << std::endl;
}
