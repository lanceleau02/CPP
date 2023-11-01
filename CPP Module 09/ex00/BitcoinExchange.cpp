/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:03:01 by laprieur          #+#    #+#             */
/*   Updated: 2023/11/01 15:29:32 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

const char*	patterns[10] = {"^(2009|20[1-9]{1}[0-9]{1}|2[1-9]{1}[0-9]{2})-(0[1-9]{1}|1[0-2]{1})-(0[1-9]{1}|[1-2]{1}[0-9]|3[0-1]{1}) \| ([+]?[0-9]+\.?[0-9]+|[+]?[0-9]+)$"};

bool	RegExr(const char* pattern, const std::string& input) {
	regex_t		regex;
	regmatch_t	match;

	if (regcomp(&regex, pattern, REG_EXTENDED) != 0)
        return false;
    if (regexec(&regex, input.c_str(), 1, &match, 0) == 0) {
		regfree(&regex);
		return true;
	}
	regfree(&regex);
	return false;
}

static bool	isDirectory(const char *path) {
	struct stat	info;
	
	if (stat(path, &info) != 0)
		return false;
	return S_ISDIR(info.st_mode);
}

bool	parsing() {
	
}

void	BitcoinExchange(const char* file) {
	std::ifstream	database;
	
	database.open(file);
	if (isDirectory(file) == true || database.is_open() == false)
		throw std::runtime_error("Error: could not open file.");
	//parsing();
}