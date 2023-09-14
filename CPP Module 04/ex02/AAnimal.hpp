/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:22:46 by laprieur          #+#    #+#             */
/*   Updated: 2023/09/14 11:45:39 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AAnimal_HPP
# define AAnimal_HPP

#include <string>
#include <iostream>

#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define NONE	"\033[0m"

class AAnimal {
	protected:
		std::string	_type;

	public:
		AAnimal();
		AAnimal(const AAnimal& source);
		AAnimal&	operator=(const AAnimal& source);
		virtual ~AAnimal();
		
		virtual void	makeSound(void) const = 0;
		std::string		getType(void) const;
};

#endif