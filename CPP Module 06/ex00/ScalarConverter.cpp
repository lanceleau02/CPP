/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:01:23 by laprieur          #+#    #+#             */
/*   Updated: 2023/10/10 17:23:08 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& source) {
	*this = source;
}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& source) {
	(void)source;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

bool isRound(float value) {
    int intValue = static_cast<int>(value); // Convert to integer
    return value == static_cast<float>(intValue); // Compare to original value
}

void	ScalarConverter::convert(const std::string& input) {
	char	charValue;
	int 	intValue = atoi(input.c_str());
	float 	floatValue;
	
	/* CHAR PART */
	
	charValue = static_cast<char>(intValue);
	std::cout << "char: ";
	if (intValue < 0 || intValue > 255)
		std::cout << "impossible" << std::endl;
	else if (isprint(intValue) == 0)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << charValue << std::endl;
	
	/* INT PART */
	
	std::cout << "int: ";
	if (intValue < INT_MIN || intValue > INT_MAX)
		std::cout << "impossible" << std::endl;
	else
		std::cout << intValue << std::endl;
	
	/* FLOAT PART */
	
	std::cout << "float: ";
	floatValue = strtof(input.c_str(), NULL);
	if (floatValue < FLT_MIN - 1e-6 || floatValue > FLT_MAX)
		std::cout << "impossible" << std::endl;
	else if (isRound(floatValue))
		std::cout << floatValue << ".0f" << std::endl;
	else
		std::cout << floatValue << "f" << std::endl;
}

/* void	display(char charValue) {
	
} */