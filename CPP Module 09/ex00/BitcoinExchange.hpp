/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:02:30 by laprieur          #+#    #+#             */
/*   Updated: 2023/11/09 14:44:41 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <sys/stat.h>
#include <fstream>
#include <sstream>
#include <map>
#include <cstdlib>

class BitcoinExchange {
    private:
        std::map<std::string, std::string>  _data;

        BitcoinExchange(const BitcoinExchange& source);
        BitcoinExchange&    operator=(const BitcoinExchange& source);

    public:
        BitcoinExchange();
        ~BitcoinExchange();
        
        bool            parseDate(const std::string& date);
        bool            parseValue(const std::string& value);
        void            parsing(std::ifstream& database);
        void            exec(const std::string& date, const std::string& value);
        void            core(const char* file);
};

#endif