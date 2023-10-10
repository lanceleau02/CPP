/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:47:10 by laprieur          #+#    #+#             */
/*   Updated: 2023/10/10 14:17:26 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ScalarConverter.hpp"

#include <iostream>
#include <string>
#include <cctype>
#include <sstream>
#include <climits>
#include <cfloat>
#include <cstring>
#include <cstdlib>
#include <limits>

bool	isInt(const std::string& input) {
	std::stringstream	ss(input);
	int					intValue;
	
	if (ss >> intValue && intValue >= INT_MIN && intValue <= INT_MAX)
		return true;
	return false;
}

int	main(void) {
	if (isInt(""))
		std::cout << "oui" << std::endl;
	else
		std::cout << "non" << std::endl;
}