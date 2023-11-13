/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 10:49:23 by laprieur          #+#    #+#             */
/*   Updated: 2023/11/13 14:31:10 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <climits>
#include <limits>
#include <cmath>
#include <regex.h>
#include <sstream>

extern const char*	patterns[10];

enum MODE {
	CHAR,
	INT,
	FLOAT,
	DOUBLE
};

class ScalarConverter {
	private:
		static std::istringstream	_input;
		static char					_charValue;
		static int					_intValue;
		static float				_floatValue;
		static double				_doubleValue;

		ScalarConverter();
		ScalarConverter(const ScalarConverter& source);
		ScalarConverter&	operator=(const ScalarConverter& source);
		~ScalarConverter();
	
	public:
		static void	convert(const std::string& input);
		static void	toChar();
		static void	toInt();
		static void	toFloat();
		static void	toDouble();
		static void	display();
		
		class InvalidInput : public std::exception {
			public:
    			virtual const char* what() const throw();
		};
};

bool	searchPattern(const char* pattern, const std::string& input);
void	displayChar(const std::string& input, char charValue);
void	displayInt(const std::string& input, int intValue);
void	displayFloat(const std::string& input, float floatValue);
void	displayDouble(const std::string& input, double doubleValue);

template <typename T>
bool	verifyValue(const T& value, int mode) {
	if (mode == CHAR && !isascii(value))
		return false;
	if (mode == INT && (value < INT_MIN || value > INT_MAX))
		return false;
	if (mode == FLOAT && value != 0.0f && (value < -std::numeric_limits<float>::max() - 1e-6 || value > std::numeric_limits<float>::max()))
		return false;
	if (mode == DOUBLE && value != 0.0 && (value < -std::numeric_limits<double>::max() - 1e-6 || value > std::numeric_limits<double>::max()))
		return false;
	return true;
}

template <typename T>
bool	isRound(const T& value) { return std::abs(value - round(value)) < 1e-9; }

template <typename T>
bool	isScientificNotation(const T& value) {
		std::ostringstream	oss;
		oss << value;
		std::string	valueStr = oss.str();

		size_t decimalPos = valueStr.find('.');
		if (decimalPos == std::string::npos)
			return false;
		size_t nbDecimalDigits = valueStr.size() - decimalPos - 1;
		return nbDecimalDigits >= 6;
}

#endif