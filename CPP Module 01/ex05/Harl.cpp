/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:23:33 by laprieur          #+#    #+#             */
/*   Updated: 2023/08/25 10:55:37 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void	Harl::debug(void) {
	std::cout
		<< "[ DEBUG ]" << std::endl
		<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger." << std::endl
		<< "I really do!" << std::endl;
}

void	Harl::info(void) {
	std::cout
		<< "[ INFO ]" << std::endl
		<< "I cannot believe adding extra bacon costs more money." << std::endl
		<< "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void) {
	std::cout
		<< "[ WARNING ]" << std::endl
		<< "I think I deserve to have some extra bacon for free." << std::endl
		<< "I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void) {
	std::cout
		<< "[ ERROR ]" << std::endl
		<< "This is unacceptable! I want to speak to the manager now." << std::endl;
}
		
void	Harl::complain(std::string level) {
	typedef void (Harl::*levels)();
	std::string	levelsName[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	levels		levelsFunc[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	Harl		harl;

	for (int i = 0; i < 4; i++) {
		if (levelsName[i] == level) {
			(harl.*levelsFunc[i])();
			return ;
		}
	}
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}