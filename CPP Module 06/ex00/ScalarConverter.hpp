/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 10:49:23 by laprieur          #+#    #+#             */
/*   Updated: 2023/10/13 16:04:46 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <ios>
#include <string>
#include <cstdlib>
#include <climits>
#include <cfloat>
#include <cmath>
#include <regex.h>
#include <cctype>
#include <iomanip>
#include <sstream>

extern const char*	patterns[10];

class ScalarConverter {
	private:
		static std::string	_input;
		static char			_charValue;
		static int			_intValue;
		static float		_floatValue;
		static double		_doubleValue;

		ScalarConverter();
		ScalarConverter(const ScalarConverter& source);
		ScalarConverter&	operator=(const ScalarConverter& source);
		~ScalarConverter();
	
	public:
		static void	convert(std::string input);
		static void	toChar();
		static void	toInt();
		static void	toFloat();
		static void	toDouble();
		static void	display();
};

bool	searchPattern(const char* pattern, std::string input);
bool	isPseudoLiteral(std::string input);
bool	verifyValue(std::string input, int mode);
template <typename T>
bool	isRound(T value) { return std::abs(value - round(value)) < 1e-9; }
template <typename T>
bool	isDecimal(T number) {
	T truncated = static_cast<T>(static_cast<int>(number));
    return std::abs(number - truncated) > 0.0;
}
template <typename T>
bool test(T number) {
    std::ostringstream oss;
    oss << number;  // Convert the float to a string
    std::string numberStr = oss.str();

    // Find the position of the decimal point (if any)
    size_t decimalPos = numberStr.find('.');
    if (decimalPos == std::string::npos) {
        return false; // No decimal point found
    }

    // Calculate the number of decimal digits
    size_t numDecimalDigits = numberStr.size() - decimalPos - 1;

    return numDecimalDigits >= 6;
}
void	displayChar(std::string input, char charValue, int intValue);
void	displayInt(std::string input, int intValue);
void	displayFloat(std::string input, float floatValue);
void	displayDouble(std::string input, double doubleValue);

#endif