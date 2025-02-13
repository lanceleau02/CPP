/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 10:23:42 by laprieur          #+#    #+#             */
/*   Updated: 2023/08/30 10:36:45 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {
	private:
		std::string	_name;
	
	public:
		Zombie();
		~Zombie();

		void	setName(const std::string& name);
		void	announce(void);
};

Zombie*	zombieHorde(int N, std::string name);

#endif
