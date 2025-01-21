/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 10:20:12 by laprieur          #+#    #+#             */
/*   Updated: 2023/08/23 11:39:22 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA {
	private:
		Weapon&		_weapon;
		std::string	_name;

	public:
		HumanA(std::string name, Weapon& weapon);
		~HumanA();
		
		void	setWeapon(Weapon& weapon);
		void	attack();
};

#endif