/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverterUtils.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 12:09:09 by laprieur          #+#    #+#             */
/*   Updated: 2023/10/13 14:28:26 by laprieur         ###   ########.fr       */
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

bool	isPseudoLiteral(std::string input) {
	if (input == "-inff" || input == "+inff" || input == "nanf"
		|| input == "-inf" || input == "+inf" || input == "nan")
		return true;
	return false;
}

void	displayChar(std::string input, char charValue) {
	std::cout << "char: ";
	if (charValue < 0 || charValue > 127 || isPseudoLiteral(input))
		std::cout << "impossible" << std::endl;
	else if (charValue < ' ' || charValue > '~')
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << charValue << std::endl;
}

void	displayInt(std::string input, int intValue) {
	std::cout << "int: ";
	if (intValue < INT_MIN || intValue > INT_MAX || isPseudoLiteral(input))
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
	else if (floatValue < FLT_MIN - 1e-6 || floatValue > FLT_MAX)
		std::cout << "impossible" << std::endl;
	else if (isRound(floatValue))
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
	else if (doubleValue < DBL_MIN - 1e-6 || doubleValue > DBL_MAX)
		std::cout << "impossible" << std::endl;
	else if (isRound(doubleValue))
		std::cout << doubleValue << ".0" << std::endl;
	else
		std::cout << doubleValue << std::endl;
}