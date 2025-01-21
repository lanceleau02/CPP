/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 11:20:17 by laprieur          #+#    #+#             */
/*   Updated: 2023/08/24 09:40:30 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	this->_nbContacts = 0;
}

PhoneBook::~PhoneBook() {}

void	PhoneBook::addContact() {
	this->_contacts[this->_nbContacts % _MAX].setFirstName(readLine("First name: ", YELLOW));
	this->_contacts[this->_nbContacts % _MAX].setLastName(readLine("Last name: ", YELLOW));
	this->_contacts[this->_nbContacts % _MAX].setNickname(readLine("Nickname: ", YELLOW));
	this->_contacts[this->_nbContacts % _MAX].setPhoneNumber(readLine("Phone number: ", YELLOW));
	this->_contacts[this->_nbContacts % _MAX].setDarkestSecret(readLine("Darkest secret: ", YELLOW));
	_nbContacts++;
}

void	PhoneBook::searchContact() {
	_printContactsArray();
	_printContact();
}

const char* PhoneBook::ReadLineExit::what() const throw() {
    return ("");
}
