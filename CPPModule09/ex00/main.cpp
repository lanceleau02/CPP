/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:02:01 by laprieur          #+#    #+#             */
/*   Updated: 2023/11/24 13:05:51 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Error: invalid argument." << std::endl;
		return 1;
	}
	try {
		BitcoinExchange	obj;
		obj.program(argv[1]);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}