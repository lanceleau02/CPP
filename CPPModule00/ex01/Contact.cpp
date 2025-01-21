/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 15:18:25 by laprieur          #+#    #+#             */
/*   Updated: 2023/08/24 09:20:05 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {}

Contact::~Contact() {}

std::string	Contact::getFirstName() const {
	return _FirstName;
}

std::string	Contact::getLastName() const {
	return _LastName;
}

std::string	Contact::getNickname() const {
	return _Nickname;
}

std::string	Contact::getPhoneNumber() const {
	return _PhoneNumber;
}

std::string	Contact::getDarkestSecret() const {
	return _DarkestSecret;
}

void	Contact::setFirstName(std::string FirstName) {
	this->_FirstName = FirstName;
}

void	Contact::setLastName(std::string LastName) {
	this->_LastName = LastName;
}

void	Contact::setNickname(std::string Nickname) {
	this->_Nickname = Nickname;
}

void	Contact::setPhoneNumber(std::string PhoneNumber) {
	this->_PhoneNumber = PhoneNumber;
}

void	Contact::setDarkestSecret(std::string DarkestSecret) {
	this->_DarkestSecret = DarkestSecret;
}
