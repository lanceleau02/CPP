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
	if (mode == CHAR && !isascii(atoi(input.c_str())))
		return false;
	if (mode == INT && (atol(input.c_str()) < INT_MIN || atol(input.c_str()) > INT_MAX))
		return false;
	if (mode == FLOAT && (strtod(input.c_str(), NULL) < FLT_MIN - 1e-6 || strtod(input.c_str(), NULL) > FLT_MAX))
		return false;
	if (mode == DOUBLE && (strtold(input.c_str(), NULL) < DBL_MIN - 1e-6 || strtold(input.c_str(), NULL) > DBL_MAX))
		return false;
	return true;
}

static bool	isPseudoLiteral(std::string input) {
	for (int i = 0; i < 6; i++)
		if (searchPattern(patterns[i], input))
			return true;
	return false;
}

static void	displayPseudoLiteral(std::string input, int mode) {
	if (input == "-inff" || input == "-inf")
		std::cout << "-inf";
	else if (input == "+inff" || input == "+inf")
		std::cout << "+inf";
	else if (input == "nanf" || input == "nan")
		std::cout << "nan";
	if (mode == FLOAT)
		std::cout << "f";
	std::cout << std::endl;
}

void	displayChar(std::string input, char charValue) {
	std::cout << "char: ";
	if (!verifyValue(input, CHAR) || isPseudoLiteral(input))
		std::cout << "impossible" << std::endl;
	else if (!isprint(charValue))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "\'" << charValue << "\'" << std::endl;
}

void	displayInt(std::string input, int intValue) {
	std::cout << "int: ";
	if (!verifyValue(input, INT) || isPseudoLiteral(input))
		std::cout << "impossible" << std::endl;
	else
		std::cout << intValue << std::endl;
}

void	displayFloat(std::string input, float floatValue) {
	std::cout << "float: ";
	if (isPseudoLiteral(input))
		displayPseudoLiteral(input, FLOAT);
	else if (!verifyValue(input, FLOAT))
		std::cout << "impossible" << std::endl;
	else if (isRound(floatValue) && !isScientificNotation(floatValue))
		std::cout << floatValue << ".0f" << std::endl;
	else
		std::cout << floatValue << "f" << std::endl;
}

void	displayDouble(std::string input, double doubleValue) {
	std::cout << "double: ";
	if (isPseudoLiteral(input))
		displayPseudoLiteral(input, DOUBLE);
	else if (!verifyValue(input, DOUBLE))
		std::cout << "impossible" << std::endl;
	else if (isRound(doubleValue) && !isScientificNotation(doubleValue))
		std::cout << doubleValue << ".0" << std::endl;
	else
		std::cout << doubleValue << std::endl;
}
