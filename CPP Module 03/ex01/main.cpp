/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 10:15:52 by laprieur          #+#    #+#             */
/*   Updated: 2023/09/01 16:57:16 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void) {
	ScavTrap	jean;
	ScavTrap	bob("bob");
	
	jean.printStats();
	bob.printStats();
	std::cout << std::endl;
	for (int i = 0; i < 51; i++)
		jean.attack("bob");
	jean.printStats();
	bob.printStats();
	std::cout << std::endl;
	for (int i = 0; i < 11; i++)
		bob.takeDamage(10);
	jean.printStats();
	bob.printStats();
	jean.guardGate();
	bob.guardGate();
	return 0;
}