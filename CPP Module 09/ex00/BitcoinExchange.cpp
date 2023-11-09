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

int  daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

static bool	isDirectory(const char* path) {
	struct stat	info;
	
	if (stat(path, &info) != 0)
		return false;
	return S_ISDIR(info.st_mode);
}

BitcoinExchange::BitcoinExchange() {
	std::ifstream	database("data.csv");
	std::string		line;

	for (size_t i = 0; i < 3; i++)
		_date[i] = 0;
	if (!database.is_open() || isDirectory("data.csv"))
		throw std::runtime_error("Error: could not open file.");
	while (getline(database, line)) {
		size_t	delim = line.find(',');
		std::string	date = line.substr(0, delim);
		std::string	exchangeRate = line.substr(delim + 1, line.length());
		_data[date] = exchangeRate;
	}
	database.close();
}

BitcoinExchange::~BitcoinExchange() {}

bool	BitcoinExchange::parseDate(const std::string& date) {
	struct tm	tm;

    for (int i = 0; i < 10; ++i) {
        if (date[i] != '-' && (i == 4 || i == 7))
			return false;
	}
	if (strptime(date.c_str(), "%F", &tm) == NULL || date.length() != 10)
		return false;
	_date[0] = tm.tm_year + 1900;
	_date[1] = tm.tm_mon + 1;
	_date[2] = tm.tm_mday;
	if ((_date[0] == 2009 && _date[1] == 1 && (_date[2] >= 2 && _date[2] <= 31))
		|| (_date[0] == 2009 && (_date[1] >= 2 && _date[1] <= 12))
		|| (_date[0] >= 2010 && (_date[1] >= 1 && _date[1] <= 12))) {
		if (_date[0] % 4 == 0 && (_date[0] % 100 != 0 || _date[0] % 400 == 0))
			daysInMonth[2] = 29;
		return _date[2] >= 1 && _date[2] <= daysInMonth[_date[1]];
	}
	return true;
}

bool	BitcoinExchange::parseValue(const std::string& value) {
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

void	BitcoinExchange::parsing(std::ifstream& database) {
	std::string	line;
	
	getline(database, line);
	if (line != "date | value") {
		std::cerr << "Error: invalid database format." << std::endl;
		return ;
	}
	while (getline(database, line)) {
		size_t	delim = line.find('|');
		if (!parseDate(line.substr(0, delim - 1)) || line.substr(delim - 1, 3) != " | ") {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		if (!parseValue(line.substr(delim + 2, line.length())))
			continue;
		//std::cout << "exec" << std::endl;
		exec(line.substr(0, delim - 1), line.substr(delim + 2, line.length()));
	}
}

std::string	BitcoinExchange::setPreviousDate(const std::string& date) {
	int	year = atoi((date.substr(0, 4)).c_str());
	int	month = atoi((date.substr(5, 2)).c_str());
    int	day = atoi((date.substr(8, 2)).c_str());

    day--;
    if (day == 0) {
        month--;
        if (month == 0) {
            month = 12;
            year--;
        }
        day = daysInMonth[month];
    }
	std::stringstream convert;
	convert << year;
	std::string	newYear = convert.str();
	convert << month;
    std::string	newMonth = (month < 10) ? "0" + convert.str() : convert.str();
	convert << day;
    std::string	newDay = (day < 10) ? "0" + convert.str() : convert.str();
	return newYear + "-" + newMonth + "-" + newDay;
}

void	BitcoinExchange::exec(const std::string& date, const std::string& value) {
	std::map<std::string, std::string>::iterator	it = _data.find(date);
	std::string										prevDate = date;

	while (it == _data.end()) {
		currDate = prevDate;
		prevDate = setPreviousDate(currDate);
		it = _data.find(prevDate);
	}
	std::cout << date << " => " << value << " = " << atof(it->second.c_str()) * atof(value.c_str()) << std::endl;
}

void	BitcoinExchange::core(const char* file) {
	std::ifstream		database(file);

	if (!database.is_open() || isDirectory(file))
		throw std::runtime_error("Error: could not open file.");
	parsing(database);
	database.close();
}