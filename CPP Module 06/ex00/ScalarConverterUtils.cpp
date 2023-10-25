/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverterUtils.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 12:09:09 by laprieur          #+#    #+#             */
/*   Updated: 2023/10/25 16:30:22 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool	searchPattern(const char* pattern, const std::string& input) {
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

static bool	isPseudoLiteral(const std::string& input) {
	for (int i = 0; i < 6; i++)
		if (searchPattern(patterns[i], input))
			return true;
	return false;
}

static void	displayPseudoLiteral(const std::string& input, int mode) {
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

void	displayChar(const std::string& input, char charValue) {
	std::cout << "char: ";
	if (!verifyValue(atoi(input.c_str()), CHAR) || isPseudoLiteral(input))
		std::cout << "impossible" << std::endl;
	else if (!isprint(charValue))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "\'" << charValue << "\'" << std::endl;
}

void	displayInt(const std::string& input, int intValue) {
	std::cout << "int: ";
	if (!verifyValue(intValue, INT) || isPseudoLiteral(input))
		std::cout << "impossible" << std::endl;
	else
		std::cout << intValue << std::endl;
}

void	displayFloat(const std::string& input, float floatValue) {
	std::cout << "float: ";
	if (isPseudoLiteral(input))
		displayPseudoLiteral(input, FLOAT);
	else if (!verifyValue(floatValue, FLOAT))
		std::cout << "impossible" << std::endl;
	else if (isRound(floatValue) && !isScientificNotation(floatValue))
		std::cout << floatValue << ".0f" << std::endl;
	else
		std::cout << floatValue << "f" << std::endl;
}

void	displayDouble(const std::string& input, double doubleValue) {
	std::cout << "double: ";
	if (isPseudoLiteral(input))
		displayPseudoLiteral(input, DOUBLE);
	else if (!verifyValue(doubleValue, DOUBLE))
		std::cout << "impossible" << std::endl;
	else if (isRound(doubleValue) && !isScientificNotation(doubleValue))
		std::cout << doubleValue << ".0" << std::endl;
	else
		std::cout << doubleValue << std::endl;
}
