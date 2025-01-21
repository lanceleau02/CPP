/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 10:37:24 by laprieur          #+#    #+#             */
/*   Updated: 2023/08/23 11:47:37 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _weapon(NULL) {
	_name = name;
}

HumanB::~HumanB() {}

void	HumanB::setWeapon(Weapon* weapon) {
	_weapon = weapon;
}

void	HumanB::attack() {
	if (_weapon == NULL)
		std::cout << _name << " attacks with their fists" << std::endl;
	else
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}