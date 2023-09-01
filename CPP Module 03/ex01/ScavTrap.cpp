/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 10:52:58 by laprieur          #+#    #+#             */
/*   Updated: 2023/09/01 16:56:58 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	_name = "Someone";
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << GREEN << "ScavTrap class Default constructor called!" << NONE << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
	_name = name;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << GREEN << "ScavTrap class String constructor called!" << NONE << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& source) {
	*this = source;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& source) {
	_name = source.getName();
	_hitPoints = source.getHitPoints();
	_energyPoints = source.getEnergyPoints();
	_attackDamage = source.getAttackDamage();
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