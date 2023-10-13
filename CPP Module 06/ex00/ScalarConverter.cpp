/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:01:23 by laprieur          #+#    #+#             */
/*   Updated: 2023/10/13 12:52:26 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void	ScalarConverter::display() {
	/* CHAR */
	std::cout << "char: ";
	if (_charValue < 0 || _charValue > 127 || isPseudoLiteral(_input))
		std::cout << "impossible" << std::endl;
	else if (_charValue < ' ' || _charValue > '~')
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << _charValue << std::endl;
	
	/* INT */
	std::cout << "int: ";
	if (_intValue < INT_MIN || _intValue > INT_MAX || isPseudoLiteral(_input))
		std::cout << "impossible" << std::endl;
	else
		std::cout << _intValue << std::endl;
		
	/* FLOAT */
	std::cout << "float: ";
	if (_input == "-inff" || _input == "-inf")
		std::cout << "-inff" << std::endl;
	else if (_input == "+inff" || _input == "+inf")
		std::cout << "+inff" << std::endl;
	else if (_input == "nanf" || _input == "nan")
		std::cout << "nanf" << std::endl;
	else if (_floatValue < FLT_MIN - 1e-6 || _floatValue > FLT_MAX)
		std::cout << "impossible" << std::endl;
	else if (isRound(_floatValue))
		std::cout << _floatValue << ".0f" << std::endl;
	else
		std::cout << _floatValue << "f" << std::endl;

	/* DOUBLE */
	std::cout << "double: ";
	if (_input == "-inff" || _input == "-inf")
		std::cout << "-inf" << std::endl;
	else if (_input == "+inff" || _input == "+inf")
		std::cout << "+inf" << std::endl;
	else if (_input == "nanf" || _input == "nan")
		std::cout << "nan" << std::endl;
	else if (_doubleValue < DBL_MIN - 1e-6 || _doubleValue > DBL_MAX)
		std::cout << "impossible" << std::endl;
	else if (isRound(_doubleValue))
		std::cout << _doubleValue << ".0" << std::endl;
	else
		std::cout << _doubleValue << std::endl;
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
	if (i < 6) {
		display();
		return ;
	}
	switch (i) {
		case 6:
			toChar();
			break ;
		case 7:
			toInt();
			break ;
		case 8:
			toFloat();
			break ;
		case 9:
			toDouble();
			break ;
		default:
			std::cout << "Error: invalid input" << std::endl;
			return ;
	}
	display();
}

void	ScalarConverter::setInput(const std::string& input) {
	_input = input;
}