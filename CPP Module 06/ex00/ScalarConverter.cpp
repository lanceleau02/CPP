/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:01:23 by laprieur          #+#    #+#             */
/*   Updated: 2023/10/10 14:04:10 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& source) {
	*this = source;
}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& source) {
	return *this;
}

ScalarConverter::~ScalarConverter() {}

static void	ScalarConverter::convert(const std::string& input) {
	
}

bool	isChar(const std::string& input) const {
	if (input.size() == 1 && isalpha(input[0]) != 0)
		return true;
	return false;
}

bool	isInt(const std::string& input) const {
	std::istringstream	iss(input);
	int					intValue;
	
	if (iss >> intValue && intValue >= INT_MIN && intValue <= INT_MAX)
		return true;
	return false;
}

bool	isFloat(const std::string& input) {
	float	floatValue = strtof(input.c_str(), NULL);
	
	if ((input == "-inff" || input == "+inff" || input == "nanf")
		|| (floatValue >= (FLT_MIN - 1e-6) && floatValue <= FLT_MAX))
		return true;
	return false;
}