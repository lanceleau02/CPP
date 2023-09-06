/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:51:02 by laprieur          #+#    #+#             */
/*   Updated: 2023/09/06 15:54:33 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
	private:
		std::string		_name;
		using FragTrap::_maxHitPoints;
		using ScavTrap::_maxEnergyPoints;
		using FragTrap::_maxAttackDamage;

	public:
		DiamondTrap();
		DiamondTrap(const std::string& name);
		DiamondTrap(const DiamondTrap& source);
		DiamondTrap&	operator=(const DiamondTrap& source);
		~DiamondTrap();
		
		void	attack(const std::string& target);
		void	whoAmI();
};

#endif
