/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 10:15:52 by laprieur          #+#    #+#             */
/*   Updated: 2023/09/06 14:19:13 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void) {
	{
		std::cout << YELLOW << "+--------+ takeDamage() TEST +--------+" << std::endl << std::endl;
		
		ClapTrap	takeDamageTest;
		
		takeDamageTest.printStats();
		std::cout << std::endl;
		for (int i = 0; i < 11; i++)
			takeDamageTest.takeDamage(1);
		takeDamageTest.printStats();
		std::cout << std::endl;
	}
	std::cout << std::endl;
	{
		std::cout << YELLOW << "+--------+ attack() TEST +--------+" << std::endl << std::endl;
		
		ClapTrap	attackTest("attackTest");
		
		attackTest.printStats();
		std::cout << std::endl;
		for (int i = 0; i < 11; i++)
			attackTest.attack("the target");
		attackTest.printStats();
		std::cout << std::endl;
	}
	std::cout << std::endl;
	{
		std::cout << YELLOW << "+--------+ beRepaired() TEST +--------+" << std::endl << std::endl;
		
		ClapTrap	beRepairedTest("beRepairedTest");
		
		beRepairedTest.printStats();
		std::cout << std::endl;
		for (int i = 0; i < 11; i++)
			beRepairedTest.beRepaired(1);
		beRepairedTest.printStats();
		std::cout << std::endl;
	}
	return 0;
}