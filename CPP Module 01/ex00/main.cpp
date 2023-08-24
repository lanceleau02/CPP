/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 11:48:18 by laprieur          #+#    #+#             */
/*   Updated: 2023/08/22 11:21:40 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(int argc, char **argv) {
	Zombie *zombie;

	(void)argv;
	if (argc != 1)
	{
		std::cerr << "Error: too many arguments." << std::endl;
		return 1;
	}
	std::cout << "+----------+ HEAP ALLOCATION +----------+" << std::endl << std::endl;
	zombie = newZombie("First Foo");
	zombie->announce();
	delete(zombie);
	std::cout << std::endl;
	std::cout << "+----------+ STACK ALLOCATION +----------+" << std::endl << std::endl;
	randomChump("Second Foo");
	return 0;
}