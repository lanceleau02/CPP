/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 14:21:33 by laprieur          #+#    #+#             */
/*   Updated: 2023/08/24 09:21:26 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(int argc, char **argv) {
	PhoneBook	phonebook;
	std::string	input;
	
	(void)argv;
	if (argc != 1) {
		std::cerr << RED << "Error: too many arguments." << std::endl;
		return 1;
	}
	try {
		std::cout << BLUE << "WELCOME TO MY AWESOME PHONEBOOK!" << NONE << std::endl;
		while (1) {
			input = readLine("Enter a command: ", GREEN);
			if (input.compare("ADD") == 0)
				phonebook.addContact();
			else if (input.compare("SEARCH") == 0)
				phonebook.searchContact();
			else if (input.compare("EXIT") == 0)
				break ;
			else {
				std::cerr << RED << "Unknown command, please enter a valid one." << NONE << std::endl;
				continue ;
			}
		}
		std::cout << BLUE << "Bye." << NONE << std::endl;
	}
	catch (std::exception &e) {
		return 1;
	}
	return 0;
}
