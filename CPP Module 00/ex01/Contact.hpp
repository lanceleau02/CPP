/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 11:14:07 by laprieur          #+#    #+#             */
/*   Updated: 2023/08/04 15:13:03 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class Contact {
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;
	
	public:
		Contact();
		~Contact();
		
		std::string	getFirst_Name() const {
			return first_name;
		}
		std::string	getLast_Name() const {
			return last_name;
		}
		std::string	getNickname() const {
			return nickname;
		}
		std::string	getPhone_Number() const {
			return phone_number;
		}
		std::string	getDarkest_Secret() const {
			return darkest_secret;
		}
};

#endif