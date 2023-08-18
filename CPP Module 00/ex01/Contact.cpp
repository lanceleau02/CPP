/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 15:18:25 by laprieur          #+#    #+#             */
/*   Updated: 2023/08/16 09:26:51 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {}

Contact::~Contact() {}

std::string	Contact::getFirstName() const {
	return FirstName;
}

std::string	Contact::getLastName() const {
	return LastName;
}

std::string	Contact::getNickname() const {
	return Nickname;
}

std::string	Contact::getPhoneNumber() const {
	return PhoneNumber;
}

std::string	Contact::getDarkestSecret() const {
	return DarkestSecret;
}

void	Contact::setFirstName(std::string FirstName) {
	this->FirstName = FirstName;
}

void	Contact::setLastName(std::string LastName) {
	this->LastName = LastName;
}

void	Contact::setNickname(std::string Nickname) {
	this->Nickname = Nickname;
}

void	Contact::setPhoneNumber(std::string PhoneNumber) {
	this->PhoneNumber = PhoneNumber;
}

void	Contact::setDarkestSecret(std::string DarkestSecret) {
	this->DarkestSecret = DarkestSecret;
}
