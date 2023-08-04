/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 11:20:17 by laprieur          #+#    #+#             */
/*   Updated: 2023/08/04 16:24:09 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	this->nb_contacts = 0;
}

PhoneBook::~PhoneBook() {}

void	PhoneBook::addContacts() {
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;

	first_name:
	std::cout << "First name: ";
	if (std::getline(std::cin, first_name) == NULL)
		return ;
	if (first_name.empty() == true)
		goto first_name;
	
	last_name:
	std::cout << "Last name: ";
	std::getline(std::cin, last_name);
	if (last_name.empty() == true)
		goto last_name;
	
	nickname:
	std::cout << "Nickname: ";
	std::getline(std::cin, nickname);
	if (nickname.empty() == true)
		goto nickname;
	
	phone_number:
	std::cout << "Phone number: ";
	std::getline(std::cin, phone_number);
	if (phone_number.empty() == true)
		goto phone_number;
	
	darkest_secret:
	std::cout << "Darkest secret: ";
	std::getline(std::cin, darkest_secret);
	if (darkest_secret.empty() == true)
		goto darkest_secret;
		
	//this->contacts[this->nb_contacts];
}