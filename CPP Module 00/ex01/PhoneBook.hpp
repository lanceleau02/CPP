/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 18:17:36 by laprieur          #+#    #+#             */
/*   Updated: 2023/08/04 15:16:19 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <cctype>
#include <string.h>

class	PhoneBook {
	private:
		static const int	MAX = 8;
		Contact 			contacts[MAX];
		int					nb_contacts;
	public:
		PhoneBook();
		~PhoneBook();
		
		void	addContacts();
		void	searchContacts();
};

#endif