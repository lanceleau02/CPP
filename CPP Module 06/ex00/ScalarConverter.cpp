/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:01:23 by laprieur          #+#    #+#             */
/*   Updated: 2023/10/12 18:24:52 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static const char*	patterns[10] = {	"^-inff$",
										"^+inff$",
										"^nanf$",
										"^-inf$",
										"^+inf$",
										"^nan$",
										"^[^0-9]{1}$",
										"^[+-]?[0-9]+$",
										"^[+-]?[0-9]+\\.{1}[0-9]+f$",
										"^[+-]?[0-9]+\\.{1}[0-9]+$"
									};

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

void	displayPseudoLiterals(const char* pseudoLiteral) {
	std::string	pl = static_cast<const char*>(pseudoLiteral);

	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (pl == "-inff" || pl == "-inf") {
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
	else if (pl == "+inff" || pl == "+inf") {
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else if (pl == "nanf" || pl == "nan") {
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
}

void	displayLiterals(char charValue, int intValue, float floatValue, double doubleValue, std::string pseudoLiteral) {
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
		std::cout << floatValue << ".0f" << std::endl;
	else
		std::cout << floatValue << "f" << std::endl;

	/* DOUBLE */
	std::cout << "double: ";
	if (pseudoLiteral == "-inf")
		std::cout << "-inf" << std::endl;
	else if (pseudoLiteral == "+inf")
		std::cout << "+inf" << std::endl;
	else if (doubleValue < DBL_MIN || doubleValue > DBL_MAX)
		std::cout << "impossible" << std::endl;
	else if (isRound(doubleValue))
		std::cout << doubleValue << ".0" << std::endl;
	else
		std::cout << doubleValue << std::endl;
}

void	ScalarConverter::toChar() {
	_charValue = _input[0];
	_intValue = static_cast<int>(_charValue);
	_floatValue = static_cast<float>(_charValue);
	_doubleValue = static_cast<double>(_charValue);
}

void	ScalarConverter::toInt() {
	_intValue = atoi(_input.c_str());
	_charValue = static_cast<char>(_intValue);
	_floatValue = static_cast<float>(_intValue);
	_doubleValue = static_cast<double>(_intValue);
}

void	ScalarConverter::toFloat() {
	_floatValue = atof(_input.c_str());
	_charValue = static_cast<char>(_floatValue);
	_intValue = static_cast<int>(_floatValue);
	_doubleValue = static_cast<double>(_floatValue);
}

void	ScalarConverter::toDouble() {
	_doubleValue = strtod(_input.c_str(), NULL);
	_charValue = static_cast<char>(_doubleValue);
	_intValue = static_cast<int>(_doubleValue);
	_floatValue = static_cast<float>(_doubleValue);
}

void	ScalarConverter::convert() {
	int i;
	
	for (i = 0; i < 10; i++)
		if (searchPattern(patterns[i], _input) == true)
			break ;
	if (i < 6)
		displayPseudoLiterals(_input.c_str());
	switch (i) {
		case 6:
			toChar();
		case 7:
			toInt();
		case 8:
			toFloat();
		case 9:
			toDouble();
		displayLiterals(_charValue, _intValue, _floatValue, _doubleValue, _input);
	}
}

void	ScalarConverter::setInput(const std::string& input) {
	_input = input;
}