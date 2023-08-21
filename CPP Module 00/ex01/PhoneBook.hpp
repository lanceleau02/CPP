/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 18:17:36 by laprieur          #+#    #+#             */
/*   Updated: 2023/08/21 10:55:04 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdlib>

#define RED		"\033[31m"
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

		class ReadLineExit : public std::exception {
			public:
    			virtual const char* what() const throw();
		};
};

std::string	readLine(std::string prompt, std::string color);

#endif
