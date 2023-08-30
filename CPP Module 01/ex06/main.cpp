/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 10:56:43 by laprieur          #+#    #+#             */
/*   Updated: 2023/08/30 11:29:05 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Error: Harl need ONE thing to complain about!" << std::endl;
		return 1;
	}
	Harl	harl;
	
	harl.complain(argv[1]);
	return 0;
}