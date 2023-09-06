/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:34:05 by laprieur          #+#    #+#             */
/*   Updated: 2023/09/06 14:49:13 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	_name = "FragTrap";
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << GREEN << "FragTrap class Default constructor called!" << NONE << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
	_name = name;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << GREEN << "FragTrap class String constructor called!" << NONE << std::endl;
}

FragTrap::FragTrap(const FragTrap& source) {
	*this = source;
	std::cout << GREEN << "FragTrap class Copy constructor called!" << NONE << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap& source) {
	_name = source.getName();
	_hitPoints = source.getHitPoints();
	_energyPoints = source.getEnergyPoints();
	_attackDamage = source.getAttackDamage();
	std::cout << GREEN << "FragTrap class Assignment operator called!" << NONE << std::endl;
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << RED << "FragTrap class Default destructor called!" << NONE << std::endl;
}

void	FragTrap::attack(const std::string& target) {
	if (verifyHitAndEnergyPoints() == false)
		return ;
	_energyPoints--;
	std::cout
		<< "FragTrap " << BLUE << _name << NONE << " attacks "
		<< RED << target << NONE << ", causing "
		<< RED << _attackDamage << NONE << " points of damage and loses "
		<< RED << "1" << NONE << " energy point!" << std::endl;
}

void	FragTrap::highFivesGuys() {
	std::cout << BLUE << "FragTrap " << _name << " is giving you a hive fives!" << NONE << std::endl;
}