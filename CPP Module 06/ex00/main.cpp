/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:47:10 by laprieur          #+#    #+#             */
/*   Updated: 2023/10/13 14:24:39 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int argc, char **argv) {
	if (argc == 2) {
		ScalarConverter::convert(argv[1]);
		return 0;
	}
	std::cout << "Error: invalid argument" << std::endl;
	return 1;
}