/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBookUtils.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 11:13:34 by laprieur          #+#    #+#             */
/*   Updated: 2023/08/24 09:43:01 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

std::string	readLine(std::string prompt, std::string color) {
	std::string	line;
	
	while (line.empty()) {
		std::cout << color << prompt << NONE;
		std::getline(std::cin, line);
		if (std::cin.eof())
			std::cerr << BLUE << "\ncin: EOF detected, bye." << NONE << std::endl;
		else if (std::cin.fail())
			std::cerr << BLUE << "\ncin: Error detected, bye." << NONE << std::endl;
		else
			continue ;
		throw PhoneBook::ReadLineExit();
	}
	return line;
}

void	printHeader() {
	std::cout << YELLOW
		<< "+----------+----------+----------+----------+" << std::endl
		<< "|     index|first name| last name|  nickname|" << std::endl
		<< "+----------+----------+----------+----------+" << std::endl;
}

void	printBorder() {
	std::cout << YELLOW
		<< std::endl << "+----------+----------+----------+----------+" << NONE << std::endl;
}

void	_printFields(std::string field) {
	if (field.size() > 10)
		std::cout << YELLOW << field.substr(0, 9) << ".";
	else
		std::cout << YELLOW << std::setw(10) << field;
	std::cout << "|";
}

void	PhoneBook::_printContactsArray() const {
	printHeader();
	for (int i = 0; i < std::min(this->_nbContacts, 8); i++) {
		std::cout << YELLOW << "|" << std::setw(10) << i << "|";
		_printFields(this->_contacts[i].getFirstName());
		_printFields(this->_contacts[i].getLastName());
		_printFields(this->_contacts[i].getNickname());
		printBorder();
	}
}

void	PhoneBook::_printContact() const {
	std::string			line;
	std::stringstream	ss;
	int					index;
	
	line = readLine("Index: ", YELLOW);
	ss << line;
	ss >> index;
	if (line.size() != 1 || !isdigit(line.at(0)) || index < 0 || index > std::min(_nbContacts - 1, 7)) {
		std::cerr << RED << "Invalid index, please enter a valid one." << NONE << std::endl;
		return ;
	}
	std::cout
		<< YELLOW << "First name: "
		<< NONE << this->_contacts[index].getFirstName() << std::endl
		<< YELLOW << "Last name: "
		<< NONE << this->_contacts[index].getLastName() << std::endl
		<< YELLOW << "Nickname: "
		<< NONE << this->_contacts[index].getNickname() << std::endl
		<< YELLOW << "Phone number: "
		<< NONE << this->_contacts[index].getPhoneNumber() << std::endl
		<< YELLOW << "Darkest secret: "
		<< NONE << this->_contacts[index].getDarkestSecret() << std::endl;
}
