/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:36:43 by laprieur          #+#    #+#             */
/*   Updated: 2023/09/12 11:39:26 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() {
	std::cout << GREEN << "WrongCat class Default constructor called!" << NONE << std::endl;
	_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& source) : WrongAnimal(source) {
	std::cout << GREEN << "WrongCat class Copy constructor called!" << NONE << std::endl;
	*this = source;
}

WrongCat&	WrongCat::operator=(const WrongCat& source) {
	std::cout << GREEN << "WrongCat class Assignment operator called!" << NONE << std::endl;
	_type = source._type;
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << RED << "WrongCat class Default destructor called!" << NONE << std::endl;
}