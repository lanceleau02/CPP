/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 10:15:52 by laprieur          #+#    #+#             */
/*   Updated: 2023/09/07 10:40:49 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void) {
	{
		std::cout << YELLOW << "+--------+ takeDamage() TEST +--------+" << std::endl << std::endl;
		
		DiamondTrap	takeDamageTest;
		
		takeDamageTest.printStats();
		std::cout << std::endl;
		for (int i = 0; i < 101; i++)
			takeDamageTest.takeDamage(1);
		takeDamageTest.printStats();
		std::cout << std::endl;
	}
	std::cout << std::endl;
	{
		std::cout << YELLOW << "+--------+ attack() TEST +--------+" << std::endl << std::endl;
		
		DiamondTrap	attackTest("attackTest");
		
		attackTest.printStats();
		std::cout << std::endl;
		for (int i = 0; i < 51; i++)
			attackTest.attack("the target");
		attackTest.printStats();
		std::cout << std::endl;
	}
	std::cout << std::endl;
	{
		std::cout << YELLOW << "+--------+ beRepaired() TEST +--------+" << std::endl << std::endl;
		
		DiamondTrap	beRepairedTest("beRepairedTest");
		
		beRepairedTest.printStats();
		std::cout << std::endl;
		for (int i = 0; i < 51; i++)
			beRepairedTest.beRepaired(1);
		beRepairedTest.printStats();
		std::cout << std::endl;
	}
	std::cout << std::endl;
	{
		std::cout << YELLOW << "+--------+ DiamondTrap TEST +--------+" << std::endl << std::endl;
		
		DiamondTrap	DiamondTrapTest("DiamondTrapTest");
		
		std::cout << std::endl;
		DiamondTrapTest.guardGate();
		DiamondTrapTest.highFivesGuys();
		DiamondTrapTest.whoAmI();
		std::cout << std::endl;
	}
	return 0;
}