/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:30:28 by laprieur          #+#    #+#             */
/*   Updated: 2023/09/07 15:28:28 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
	private:
		static const unsigned int	_maxHitPoints = 100;
		static const unsigned int	_maxEnergyPoints = 100;
		static const unsigned int	_maxAttackDamage = 30;

	public:
		FragTrap();
		FragTrap(const std::string& name);
		FragTrap(const FragTrap& source);
		FragTrap&	operator=(const FragTrap& source);
		~FragTrap();

		void	highFivesGuys(void);
};

#endif