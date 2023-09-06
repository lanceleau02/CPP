/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:30:28 by laprieur          #+#    #+#             */
/*   Updated: 2023/09/06 15:44:43 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
	protected:
		static const unsigned int	_maxHitPoints;
		static const unsigned int	_maxEnergyPoints;
		static const unsigned int	_maxAttackDamage;

	public:
		FragTrap();
		FragTrap(const std::string& name);
		FragTrap(const FragTrap& source);
		FragTrap&	operator=(const FragTrap& source);
		virtual ~FragTrap();
		
		void	attack(const std::string& target);
		void	highFivesGuys(void);
};

#endif