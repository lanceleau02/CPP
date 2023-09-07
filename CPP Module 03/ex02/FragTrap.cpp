/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:34:05 by laprieur          #+#    #+#             */
/*   Updated: 2023/09/07 14:53:57 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() :
	ClapTrap("FragTrap", _maxHitPoints, _maxEnergyPoints, _maxAttackDamage) {
	std::cout << GREEN << "FragTrap class Default constructor called!" << NONE << std::endl;
}

FragTrap::FragTrap(const std::string& name) :
	ClapTrap(name, _maxHitPoints, _maxEnergyPoints, _maxAttackDamage) {
	std::cout << GREEN << "FragTrap class String constructor called!" << NONE << std::endl;
}

FragTrap::FragTrap(const FragTrap& source) {
	*this = source;
	std::cout << GREEN << "FragTrap class Copy constructor called!" << NONE << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap& source) {
	_name = source._name;
	_hitPoints = source._hitPoints;
	_energyPoints = source._energyPoints;
	_attackDamage = source._attackDamage;
	std::cout << GREEN << "FragTrap class Assignment operator called!" << NONE << std::endl;
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << RED << "FragTrap class Default destructor called!" << NONE << std::endl;
}

void	FragTrap::highFivesGuys() {
	std::cout << BLUE << "FragTrap " << _name << " is giving you a high five!" << NONE << std::endl;
}