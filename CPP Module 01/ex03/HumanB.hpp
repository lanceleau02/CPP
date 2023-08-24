/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 10:36:34 by laprieur          #+#    #+#             */
/*   Updated: 2023/08/23 11:37:14 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {
	private:
		Weapon*		_weapon;
		std::string	_name;

	public:
		HumanB(std::string name);
		~HumanB();

		void	setWeapon(Weapon* weapon);
		void	attack();
};

#endif