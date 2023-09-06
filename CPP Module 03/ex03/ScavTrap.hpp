/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 10:53:01 by laprieur          #+#    #+#             */
/*   Updated: 2023/09/06 15:44:39 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	protected:
		static const unsigned int	_maxHitPoints;
		static const unsigned int	_maxEnergyPoints;
		static const unsigned int	_maxAttackDamage;

	public:
		ScavTrap();
		ScavTrap(const std::string& name);
		ScavTrap(const ScavTrap& source);
		ScavTrap&	operator=(const ScavTrap& source);
		virtual ~ScavTrap();
		
		void	attack(const std::string& target);
		void	guardGate();
};

#endif