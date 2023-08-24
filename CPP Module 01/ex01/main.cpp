/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 10:23:09 by laprieur          #+#    #+#             */
/*   Updated: 2023/08/22 15:04:35 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void) {
	Zombie*	horde;

	horde = zombieHorde(10, "Jean-Jacques");
	for(int i = 0; i < 10; i++) {
		horde[i].announce();
	}
	delete [] (horde);
}