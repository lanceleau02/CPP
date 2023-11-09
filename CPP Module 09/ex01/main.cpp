/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:11:30 by laprieur          #+#    #+#             */
/*   Updated: 2023/11/09 15:10:58 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main() {
	if (argc != 2) {
		std::cerr << "Error: invalid argument." << std::endl;
		return 1;
	}
	try {
		RPN	obj;
		obj.core(argv[1]);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}