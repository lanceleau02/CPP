/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:47:10 by laprieur          #+#    #+#             */
/*   Updated: 2023/10/25 11:21:29 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int argc, char **argv) {	
	if (argc == 2) {
		ScalarConverter::convert(argv[1]);
		return 0;
	}
	std::cerr << "Error: invalid argument" << std::endl;
	return 1;
}
