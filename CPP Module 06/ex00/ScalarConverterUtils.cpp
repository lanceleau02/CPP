/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverterUtils.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 12:09:09 by laprieur          #+#    #+#             */
/*   Updated: 2023/10/13 16:30:36 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool	searchPattern(const char* pattern, std::string input) {
	regex_t		regex;
	regmatch_t	match;

	if (regcomp(&regex, pattern, REG_EXTENDED) != 0)
        return false;
    if (regexec(&regex, input.c_str(), 1, &match, 0) == 0) {
		regfree(&regex);
		return true;
	}
	regfree(&regex);
	return false;
}

bool	verifyValue(std::string input, int mode) {
	if (mode == 0 && (atol(input.c_str()) < INT_MIN || atol(input.c_str()) > INT_MAX))
		return false;
	if (mode == 1 && (strtod(input.c_str(), NULL) < FLT_MIN - 1e-6 || strtod(input.c_str(), NULL) > FLT_MAX))
		return false;
	if (mode == 2 && (strtold(input.c_str(), NULL) < DBL_MIN - 1e-6 || strtold(input.c_str(), NULL) > DBL_MAX))
		return false;
	return true;
}

bool	isPseudoLiteral(std::string input) {
	for (int i = 0; i < 6; i++)
		if (searchPattern(patterns[i], input) == true)
			return true;
	return false;
}

void	displayChar(std::string input, char charValue, int intValue) {
	std::cout << "char: ";
	if (!isascii(intValue) || isPseudoLiteral(input))
		std::cout << "impossible" << std::endl;
	else if (!isprint(charValue))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "\'" << charValue << "\'" << std::endl;
}

void	displayInt(std::string input, int intValue) {
	std::cout << "int: ";
	if (verifyValue(input, 0) == false || isPseudoLiteral(input) == true)
		std::cout << "impossible" << std::endl;
	else
		std::cout << intValue << std::endl;
}

void	displayFloat(std::string input, float floatValue) {
	std::cout << "float: ";
	if (input == "-inff" || input == "-inf")
		std::cout << "-inff" << std::endl;
	else if (input == "+inff" || input == "+inf")
		std::cout << "+inff" << std::endl;
	else if (input == "nanf" || input == "nan")
		std::cout << "nanf" << std::endl;
	else if (verifyValue(input, 1) == false)
		std::cout << "impossible" << std::endl;
	else if (isRound(floatValue) && !isDecimal(floatValue))
		std::cout << floatValue << ".0f" << std::endl;
	else
		std::cout << floatValue << "f" << std::endl;
}

void	displayDouble(std::string input, double doubleValue) {
	std::cout << "double: ";
	if (input == "-inff" || input == "-inf")
		std::cout << "-inf" << std::endl;
	else if (input == "+inff" || input == "+inf")
		std::cout << "+inf" << std::endl;
	else if (input == "nanf" || input == "nan")
		std::cout << "nan" << std::endl;
	else if (verifyValue(input, 2) == false)
		std::cout << "impossible" << std::endl;
	else if (isRound(doubleValue) && !isDecimal(doubleValue))
		std::cout << doubleValue << ".0" << std::endl;
	else
		std::cout << doubleValue << std::endl;
}
