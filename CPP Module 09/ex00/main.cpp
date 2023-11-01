/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:02:01 by laprieur          #+#    #+#             */
/*   Updated: 2023/11/01 15:12:09 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#include <iostream>

int	main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Error: invalid argument" << std::endl;
		return 1;
	}
	BitcoinExchange(argv[1]);
	return 0;
}