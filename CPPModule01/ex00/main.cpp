/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 11:48:18 by laprieur          #+#    #+#             */
/*   Updated: 2023/08/30 10:07:55 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void) {
	Zombie *zombie;

	std::cout << "+----------+ HEAP ALLOCATION +----------+" << std::endl << std::endl;
	zombie = newZombie("First Foo");
	zombie->announce();
	delete(zombie);
	std::cout << std::endl;
	std::cout << "+----------+ STACK ALLOCATION +----------+" << std::endl << std::endl;
	randomChump("Second Foo");
	return 0;
}