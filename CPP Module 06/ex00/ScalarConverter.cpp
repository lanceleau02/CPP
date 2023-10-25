/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:01:23 by laprieur          #+#    #+#             */
/*   Updated: 2023/10/25 16:44:04 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

const char*	patterns[10] = {"^\\-inff$", "^\\+inff$", "^nanf$", "^\\-inf$",
							"^\\+inf$", "^nan$", "^[^0-9]{1}$", "^[+-]?[0-9]+$",
							"^[+-]?[0-9]+\\.{1}[0-9]+f$", "^[+-]?[0-9]+\\.{1}[0-9]+$"};

std::istringstream	ScalarConverter::_input;
char				ScalarConverter::_charValue;
int					ScalarConverter::_intValue;
float				ScalarConverter::_floatValue;
double				ScalarConverter::_doubleValue;

void	ScalarConverter::toChar() {
	_input.get(_charValue);
	if (_input.fail())
		throw ScalarConverter::InvalidInput();
	_intValue = static_cast<int>(_charValue);
	_floatValue = static_cast<float>(_charValue);
	_doubleValue = static_cast<double>(_charValue);
}

void	ScalarConverter::toInt() {
	_input >> _intValue;
	if (_input.fail())
		throw ScalarConverter::InvalidInput();
	_charValue = static_cast<char>(_intValue);
	_floatValue = static_cast<float>(_intValue);
	_doubleValue = static_cast<double>(_intValue);
}

void	ScalarConverter::toFloat() {
	_input >> _floatValue;
	if (_input.fail())
		throw ScalarConverter::InvalidInput();
	_charValue = static_cast<char>(_floatValue);
	_intValue = static_cast<int>(_floatValue);
	_doubleValue = static_cast<double>(_floatValue);
}

void	ScalarConverter::toDouble() {
	_input >> _doubleValue;
	if (_input.fail())
		throw ScalarConverter::InvalidInput();
	_charValue = static_cast<char>(_doubleValue);
	_intValue = static_cast<int>(_doubleValue);
	_floatValue = static_cast<float>(_doubleValue);
}

void	ScalarConverter::display() {
	displayChar(_input.str(), _charValue);
	displayInt(_input.str(), _intValue);
	displayFloat(_input.str(), _floatValue);
	displayDouble(_input.str(), _doubleValue);
}

const char*	ScalarConverter::InvalidInput::what() const throw() {
	return ("Error: invalid input");
}

void	ScalarConverter::convert(std::string input) {
	int i;

	_input.str(input);
	for (i = 0; i < 10; i++)
		if (searchPattern(patterns[i], _input.str()))
			break ;
	try {
		if (i == 6)
			toChar();
		else if (i == 7)
			toInt();
		else if (i == 8)
			toFloat();
		else if (i == 9)
			toDouble();
		else if (i > 6)
			throw ScalarConverter::InvalidInput();
		display();
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}
