/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:01:23 by laprieur          #+#    #+#             */
/*   Updated: 2023/10/12 13:21:04 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool	searchPattern(const char* pattern, std::string input) {
	regex_t		regex;
	regmatch_t	match;

	if (regcomp(&regex, pattern, REG_EXTENDED) != 0)
        return false;
    else if (regexec(&regex, input.c_str(), 1, &match, 0) == 0) {
		regfree(&regex);
		return true;
	}
	regfree(&regex);
	return false;
}

template <typename T>
bool	isRound(T value) {
    return std::abs(value - round(value)) < 1e-9;
}

void	display(char charValue, int intValue, float floatValue, double doubleValue, std::string pseudoLiteral) {
	/* CHAR */
	std::cout << "char: ";
	if (charValue < 0 || charValue > 127)
		std::cout << "impossible" << std::endl;
	else if (charValue < ' ' || charValue > '~')
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << charValue << std::endl;
	
	/* INT */
	std::cout << "int: ";
	if (intValue < INT_MIN || intValue > INT_MAX)
		std::cout << "impossible" << std::endl;
	else
		std::cout << intValue << std::endl;
		
	/* FLOAT */
	std::cout << "float: ";
	if (pseudoLiteral == "-inff")
		std::cout << "-inff" << std::endl;
	else if (pseudoLiteral == "+inff")
		std::cout << "+inff" << std::endl;
	else if (floatValue < FLT_MIN - 1e-6 || floatValue > FLT_MAX)
		std::cout << "impossible" << std::endl;
	else if (isRound(floatValue))
		std::cout << "float: " << floatValue << ".0f" << std::endl;
	else
		std::cout << "float: " << floatValue << "f" << std::endl;

	/* DOUBLE */
	std::cout << "double: ";
	if (pseudoLiteral == "-inf")
		std::cout << "-inf" << std::endl;
	else if (pseudoLiteral == "+inf")
		std::cout << "+inf" << std::endl;
	else if (doubleValue < DBL_MIN || doubleValue > DBL_MAX)
		std::cout << "impossible" << std::endl;
	if (isRound(doubleValue))
		std::cout << "double: " << doubleValue << ".0" << std::endl;
	else
		std::cout << "double: " << doubleValue << std::endl;
}

// test = strtod(string)
// test == std::numeric_limits<double>::infinty()

void	ScalarConverter::convert(const std::string& input) {
	char	charValue = '\0';
	int		intValue = 0;
	float	floatValue = 0.0f;
	double	doubleValue = 0.0;
	

	/* HANDLE PSEUDO LITERALS */
	
	if (searchPattern("^-inff$", input) == true || searchPattern("^+inff$", input) == true
		|| searchPattern("^nanf$", input) == true) {
		std::cout << "Limite de float." << std::endl;
		display(charValue, intValue, floatValue, doubleValue, "-inff");
	}
	else if (searchPattern("^-inf$", input) == true || searchPattern("^+inf$", input) == true
		|| searchPattern("^nan$", input) == true) {
		std::cout << "Limite de double." << std::endl;
		display(charValue, intValue, floatValue, doubleValue, "");
	}
	else if (searchPattern("^[^0-9]{1}$", input) == true) {
		std::cout << "Ceci est un char" << std::endl;
		
		charValue = input[0];
		intValue = static_cast<int>(charValue);
		floatValue = static_cast<float>(charValue);
		doubleValue = static_cast<double>(charValue);
		
		display(charValue, intValue, floatValue, doubleValue, "");
	}	
	else if (searchPattern("^[+-]?[0-9]+$", input) == true) {
		std::cout << "Ceci est un int" << std::endl;
		
		intValue = atoi(input.c_str());
		charValue = static_cast<char>(intValue);
		floatValue = static_cast<float>(intValue);
		doubleValue = static_cast<double>(intValue);
		
		display(charValue, intValue, floatValue, doubleValue, "");
	}
	else if (searchPattern("^[+-]?[0-9]+\\.{1}[0-9]+f$", input) == true) {
		std::cout << "Ceci est un float" << std::endl;
		
		floatValue = atof(input.c_str());
		charValue = static_cast<char>(floatValue);
		intValue = static_cast<int>(floatValue);
		doubleValue = static_cast<double>(floatValue);
		
		display(charValue, intValue, floatValue, doubleValue, "");
	}
	else if (searchPattern("^[+-]?[0-9]+\\.{1}[0-9]+$", input) == true) {
		std::cout << "Ceci est un double" << std::endl;
		
		doubleValue = strtod(input.c_str(), NULL);
		charValue = static_cast<char>(doubleValue);
		intValue = static_cast<int>(doubleValue);
		floatValue = static_cast<float>(doubleValue);
	
		display(charValue, intValue, floatValue, doubleValue, "");
	}
	else
		std::cout << "Error: invalid input" << std::endl;
}