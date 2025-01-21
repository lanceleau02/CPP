/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:03:01 by laprieur          #+#    #+#             */
/*   Updated: 2023/11/27 11:07:53 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
	std::ifstream	database("data.csv");
	std::string		line;

	if (!database.is_open() || isDirectory("data.csv"))
		throw std::runtime_error("Error: could not open file.");
	if (database.peek() == std::ifstream::traits_type::eof())
		throw std::runtime_error("Error: invalid database");
	getline(database, line);
	if (line != "date,exchange_rate")
		throw std::runtime_error("Error: invalid database format");
	while (getline(database, line)) {
		size_t	delim = line.find(',');
		std::string	date = line.substr(0, delim);
		if (!parseDate(date))
			throw std::runtime_error("Error: invalid database.");
		std::string	exchangeRate = line.substr(delim + 1, line.length());
		_data[date] = exchangeRate;
	}
	database.close();
}

BitcoinExchange::~BitcoinExchange() {}

void	BitcoinExchange::program(const char* file) {
	std::ifstream	database(file);

	if (!database.is_open() || isDirectory(file))
		throw std::runtime_error("Error: could not open file.");
	std::string	line;
	getline(database, line);
	if (line != "date | value")
		throw std::runtime_error("Error: invalid database format.");
	while (getline(database, line)) {
		size_t	delim = line.find('|');
		if (!parseDate(line.substr(0, delim - 1)) || line.substr(delim - 1, 3) != " | ") {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		if (!parseValue(line.substr(delim + 2, line.length())))
			continue;
		std::string	date = line.substr(0, delim - 1);
		std::string	value = line.substr(delim + 2, line.length());
		std::map<std::string, std::string>::iterator	it = _data.find(date);
		if (date < _data.begin()->first) {
			std::cerr << "Error: impossible to find in database" << std::endl;
			continue;
		}
		if (it == _data.end()) {
			it = _data.lower_bound(date);
			if (it != _data.begin())
				--it;
		}
		std::cout << date << " => " << value << " = " << atof(it->second.c_str()) * atof(value.c_str()) << std::endl;
	}
	database.close();
}

bool	isDirectory(const char* path) {
	struct stat	info;
	
	if (stat(path, &info) != 0)
		return false;
	return S_ISDIR(info.st_mode);
}

bool	parseDate(const std::string& date) {
	struct tm	tm;
	int			daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    for (int i = 0; i < 10; ++i) {
        if (date[i] != '-' && (i == 4 || i == 7))
			return false;
	}
	if (strptime(date.c_str(), "%F", &tm) == NULL || date.length() != 10)
		return false;
	int year = tm.tm_year + 1900;
	int month = tm.tm_mon + 1;
	int day = tm.tm_mday;
	if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
		daysInMonth[2] = 29;
	return day >= 1 && day <= daysInMonth[month];
}

bool	parseValue(const std::string& value) {
	std::stringstream	ss;
	float				floatValue;
	long				longValue;

	if (!(ss << value) || (value.find_first_not_of("0123456789+-.") != std::string::npos))
		std::cerr << "Error: not a valid number." << std::endl;
	else if (value.find(".") != std::string::npos && ss >> floatValue && (floatValue < 0.00 || floatValue > 1000.00))
		std::cerr << "Error: " << (floatValue < 0.00 ? "not a positive" : "too large a") << " number." << std::endl;
	else if (ss >> longValue && (longValue < 0 || longValue > 1000))
		std::cerr << "Error: " << (longValue < 0 ? "not a positive" : "too large a") << " number." << std::endl;
	else
		return true;
	return false;
}