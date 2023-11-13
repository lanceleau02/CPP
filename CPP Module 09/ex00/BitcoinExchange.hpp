/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:02:30 by laprieur          #+#    #+#             */
/*   Updated: 2023/11/13 11:37:33 by laprieur         ###   ########.fr       */
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

        void	program(const char* file);
};

#endif