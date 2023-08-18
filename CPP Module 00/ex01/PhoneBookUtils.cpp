/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBookUtils.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 11:13:34 by laprieur          #+#    #+#             */
/*   Updated: 2023/08/17 11:22:58 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	PhoneBook::_incrementNbContacts() {
	_nbContacts++;
}

std::string	readLine(std::string prompt, std::string color) {
	std::string	line;
	
	while (line.empty())
	{
		std::cout << color << prompt << NONE;
		std::getline(std::cin, line);
		if (std::cin.eof())
			std::cout << "\ncin: EOF detected, bye." << std::endl;
		else if (std::cin.fail())
			std::cout << "\ncin: Error detected, bye." << std::endl;
		else
			continue ;
		exit(1);
	}
	return (line);
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
			std::cout << field.substr(0, 9) << ".";
		else
			std::cout << std::setw(10) << field;
	std::cout << "|";
}

void	PhoneBook::_printContactsArray() const {
	printHeader();
	for (int i = 0; i < std::min(this->_nbContacts, 8); i++)
	{
		std::cout << "|";
		std::cout << std::setw(10) << i;
		std::cout << "|";
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
	if (index < 0 || index > std::min(_nbContacts - 1, 8))
	{
		std::cout << "Invalid index, please enter a valid one." << std::endl;
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
