/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 10:49:23 by laprieur          #+#    #+#             */
/*   Updated: 2023/10/13 13:42:54 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <climits>
#include <cfloat>
#include <cmath>
#include <regex.h>

static const char*	patterns[10] = {"^\\-inff$", "^\\+inff$", "^nanf$", "^\\-inf$",
									"^\\+inf$", "^nan$", "^[^0-9]{1}$",
									"^[+-]?[0-9]+$", "^[+-]?[0-9]+\\.{1}[0-9]+f$",
									"^[+-]?[0-9]+\\.{1}[0-9]+$"};

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
		static void	toChar();
		static void	toInt();
		static void	toFloat();
		static void	toDouble();
		static void	display();
		static void	convert();
		static void	setInput(const std::string& input);
};

bool	isPseudoLiteral(std::string input);
bool	searchPattern(const char* pattern, std::string input);
template <typename T>
bool	isRound(T value) { return std::abs(value - round(value)) < 1e-9; }

#endif