/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:03:01 by laprieur          #+#    #+#             */
/*   Updated: 2023/11/02 15:28:09 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

static bool	isDirectory(const char *path) {
	struct stat	info;
	
	if (stat(path, &info) != 0)
		return false;
	return S_ISDIR(info.st_mode);
}

bool	isValidDate(const std::string& date) {
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
}

bool	parseDate(const std::string& date) {
	time_t		rawtime;
	char		buffer[11];

	time(&rawtime);
	if (strftime(buffer, 11, "%F", localtime(&rawtime)) == 0 || !isValidDate(date))
		return false;
	return true;
}

template <typename T>
bool	parseValue(T value) {
	if (value < 0 || value > 1000)
		return false;
	return true;
}

bool	parsing(std::ifstream& database) {
	std::string	line;

	while (getline(database, line))
		if (!parseDate(line.substr(0, 10) || line.substr(10, 3) != " | " || !parseValue(line.substr(13, (line.length() - 13)))))
			throw std::runtime_error("Error: invalid database format.");
	return true;
}

void	BitcoinExchange(const char* file) {
	std::ifstream		database(file);

	if (!database.is_open())
		throw std::runtime_error("Error: could not open file.");
	parsing(database);
}