/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:22:46 by laprieur          #+#    #+#             */
/*   Updated: 2023/09/13 11:05:24 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WrongAnimal_HPP
# define WrongAnimal_HPP

#include <string>
#include <iostream>

#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define BLUE	"\033[34m"
#define NONE	"\033[0m"

class WrongAnimal {
	protected:
		std::string	_type;

	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal& source);
		WrongAnimal&	operator=(const WrongAnimal& source);
		virtual ~WrongAnimal();
		
		void		makeSound(void) const;
		std::string	getType(void) const;
};

#endif