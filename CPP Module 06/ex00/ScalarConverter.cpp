/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:01:23 by laprieur          #+#    #+#             */
/*   Updated: 2023/10/11 15:42:51 by laprieur         ###   ########.fr       */
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

void	ScalarConverter::convert(const std::string& input) {
	if (searchPattern("^[+-]?[0-9]*$", input) == true)
		std::cout << "Ceci est un int" << std::endl;
	else if (searchPattern("^[+-]?[0-9]+\\.{1}[0-9]+f$", input) == true)
		std::cout << "Ceci est un float" << std::endl;
	else if (searchPattern("^[+-]?[0-9]+\\.{1}[0-9]+$", input) == true)
		std::cout << "Ceci est un double" << std::endl;
	else if (searchPattern("^[ -~]$", input) == true)
		std::cout << "Ceci est un char" << std::endl;
	else
		std::cout << "Ceci est une erreur" << std::endl;
}

bool	isRound(float value) {
    int intValue = static_cast<int>(value); 
    return value == static_cast<float>(intValue);
}