/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:30:28 by laprieur          #+#    #+#             */
/*   Updated: 2023/09/07 11:27:24 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap {
	protected:
		static const unsigned int	_maxHitPoints = 100;
		static const unsigned int	_maxEnergyPoints = 100;
		static const unsigned int	_maxAttackDamage = 30;

	public:
		FragTrap();
		FragTrap(const std::string& name);
		FragTrap(const FragTrap& source);
		FragTrap&	operator=(const FragTrap& source);
		virtual ~FragTrap();

		void	highFivesGuys(void);
};

#endif