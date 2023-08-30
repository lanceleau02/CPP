/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:41:27 by laprieur          #+#    #+#             */
/*   Updated: 2023/08/30 17:00:49 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name(""), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap class Default constructor called!" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap class String constructor called!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& source) {
	*this = source;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& source) {
	
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap class Default destructor called!" << std::endl;
}

void	ClapTrap::attack(const std::string& target) {

}

void	ClapTrap::takeDamage(unsigned int amount) {
	
}

void	ClapTrap::beRepaired(unsigned int amount) {
	
}

