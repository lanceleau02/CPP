/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:01:23 by laprieur          #+#    #+#             */
/*   Updated: 2023/10/13 16:03:53 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

std::string ScalarConverter::_input;
char		ScalarConverter::_charValue;
int			ScalarConverter::_intValue;
float		ScalarConverter::_floatValue;
double		ScalarConverter::_doubleValue;

void	ScalarConverter::display() {
	displayChar(_input, _charValue);
	displayInt(_input, _intValue);
	displayFloat(_input, _floatValue);
	displayDouble(_input, _doubleValue);
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

void	ScalarConverter::convert(std::string input) {
	int i;
	
	_input = input;
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
