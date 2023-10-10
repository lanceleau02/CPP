/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 10:49:23 by laprieur          #+#    #+#             */
/*   Updated: 2023/10/10 14:04:29 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cctype>
#include <sstream>
#include <climits>
#include <cfloat>
#include <cstring>
#include <cstdlib>
#include <limits>

class ScalarConverter {
	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& source);
		ScalarConverter&	operator=(const ScalarConverter& source);
		~ScalarConverter();

		static void	convert(const std::string& input);
};

bool	isChar(const std::string& input) const;

#endif