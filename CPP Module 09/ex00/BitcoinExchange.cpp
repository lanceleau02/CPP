/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:03:01 by laprieur          #+#    #+#             */
/*   Updated: 2023/11/03 16:03:49 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool	isDirectory(const char* path) {
	struct stat	info;
	
	if (stat(path, &info) != 0)
		return false;
	return S_ISDIR(info.st_mode);
}

/* bool	isValidDate(const std::string& date) {
	int	year = atoi((date.substr(0, 4)).c_str());
	int	month = atoi((date.substr(5, 2)).c_str());
	int day = atoi((date.substr(8, 2)).c_str());
	int	daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if ((year == 2009 && month == 1 && (day >= 2 && day <= 31))
		|| (year == 2009 && (month >= 2 && month <= 12))
		|| (year >= 2010 && (month >= 1 && month <= 12))) {
		if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
			daysInMonth[2] = 29;
		return day >= 1 && day <= daysInMonth[month];
	}
	return false;
} */

bool	parseDate(const std::string& date) {
	struct tm	tm;
	int			daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    for (int i = 0; i < 10; ++i) {
        if (date[i] != '-' && (i == 4 || i == 7))
			return false;
	}
	if (strptime(date.c_str(), "%F", &tm) == NULL || date.length() != 10)
		return false;
	std::cout << tm.tm_year + 1900 << std::endl;
	std::cout << tm.tm_mon  + 1 << std::endl;
	std::cout << tm.tm_mday << std::endl;
	if ((tm.tm_year == 2009 && tm.tm_mon == 1 && (tm.tm_mday >= 2 && tm.tm_mday <= 31))
		|| (tm.tm_year == 2009 && (tm.tm_mon >= 2 && tm.tm_mon <= 12))
		|| (tm.tm_year >= 2010 && (tm.tm_mon >= 1 && tm.tm_mon <= 12))) {
		if (tm.tm_year % 4 == 0 && (tm.tm_year % 100 != 0 || tm.tm_year % 400 == 0))
			daysInMonth[2] = 29;
		return tm.tm_mday >= 1 && tm.tm_mday <= daysInMonth[tm.tm_mon];
	}
	return true;
}

bool	parseValue(const std::string& value) {
	std::stringstream	ss;
	float				floatValue;
	int					intValue;

	if (value.find_first_not_of("0123456789+.") != std::string::npos)
		return false;
	ss << value;
	if (value.find(".") != std::string::npos && ss >> floatValue)
		if (floatValue < 0.00 || floatValue > 1000.00)
			return false;
	if (ss >> intValue)
		if (intValue < 0 || intValue > 1000)
			return false;
	return true;
}

bool	parsing(std::ifstream& database) {
	std::string	line;

	while (getline(database, line))
		if (!parseDate(line.substr(0, 10)) || line.substr(10, 3) != " | " || !parseValue(line.substr(13, line.length() - 13)))
			throw std::runtime_error("Error: invalid database format.");
	return true;
}

void	BitcoinExchange(const char* file) {
	std::ifstream		database(file);

	if (!database.is_open() || isDirectory(file))
		throw std::runtime_error("Error: could not open file.");
	parsing(database);
}