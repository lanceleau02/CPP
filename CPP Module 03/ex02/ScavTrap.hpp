/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 10:53:01 by laprieur          #+#    #+#             */
/*   Updated: 2023/09/07 15:28:34 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	private:
		static const unsigned int	_maxHitPoints = 100;
		static const unsigned int	_maxEnergyPoints = 50;
		static const unsigned int	_maxAttackDamage = 20;

	public:
		ScavTrap();
		ScavTrap(const std::string& name);
		ScavTrap(const ScavTrap& source);
		ScavTrap&	operator=(const ScavTrap& source);
		~ScavTrap();
		
		void	attack(const std::string& target);
		void	guardGate();
};

#endif