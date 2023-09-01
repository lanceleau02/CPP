/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:41:27 by laprieur          #+#    #+#             */
/*   Updated: 2023/09/01 16:35:11 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Someone"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << GREEN << "ClapTrap class Default constructor called!" << NONE << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << GREEN << "ClapTrap class String constructor called!" << NONE << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& source) {
	*this = source;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& source) {
	_name = source.getName();
	_hitPoints = source.getHitPoints();
	_energyPoints = source.getEnergyPoints();
	_attackDamage = source.getAttackDamage();
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << RED << "ClapTrap class Default destructor called!" << NONE << std::endl;
}

std::string	ClapTrap::getName() const {
	return _name;
}

int	ClapTrap::getHitPoints() const {
	return _hitPoints;
}

int	ClapTrap::getEnergyPoints() const {
	return _energyPoints;
}

int	ClapTrap::getAttackDamage() const {
	return _attackDamage;
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
