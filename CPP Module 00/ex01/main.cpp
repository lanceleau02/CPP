/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 14:21:33 by laprieur          #+#    #+#             */
/*   Updated: 2023/08/04 15:20:16 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void) {
	PhoneBook	phonebook;
	std::string	input;

	while (1)
	{
		std::cout << "Enter a command: ";
		getline(std::cin, input);
		if (input.compare("ADD") == 0)
			phonebook.addContacts();
		/* else if (input.compare("SEARCH") == 0)
			phonebook.searchContacts(); */
		else if (input.compare("EXIT") == 0)
			break ;
		else
		{
			std::cout << "Unknown command, please enter a valid one." << std::endl;
			continue ;
		}
	}
	return (0);
}