/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 10:15:52 by laprieur          #+#    #+#             */
/*   Updated: 2023/09/01 16:43:49 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void) {
	ClapTrap	jean;
	ClapTrap	bob("bob");
	
	jean.printStats();
	bob.printStats();
	std::cout << std::endl;
	for (int i = 0; i < 11; i++)
		jean.attack("bob");
	jean.printStats();
	bob.printStats();
	std::cout << std::endl;
	for (int i = 0; i < 3; i++)
		bob.takeDamage(5);
	jean.printStats();
	bob.printStats();
	return 0;
}