/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 18:17:36 by laprieur          #+#    #+#             */
/*   Updated: 2023/08/17 11:40:17 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cstdlib>

#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define WHITE	"\033[37m"
#define NONE	"\033[0m"

class	PhoneBook {
	private:
		static const int	_MAX = 8;
		Contact 			_contacts[_MAX];
		int					_nbContacts;
		
		void	_incrementNbContacts();
		void	_printContactsArray() const;
		void	_printContact() const;

	public:
		PhoneBook();
		~PhoneBook();
		
		void	addContact();
		void	searchContact();
};

std::string	readLine(std::string prompt, std::string color);

#endif
