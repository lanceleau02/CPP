/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:36:43 by laprieur          #+#    #+#             */
/*   Updated: 2023/09/12 09:42:44 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
	std::cout << GREEN << "Dog class Default constructor called!" << NONE << std::endl;
	_type = "Dog";
}

Dog::Dog(const Dog& source) : Animal(source) {
	std::cout << GREEN << "Dog class Copy constructor called!" << NONE << std::endl;
	*this = source;
}

Dog&	Dog::operator=(const Dog& source) {
	std::cout << GREEN << "Dog class Assignment operator called!" << NONE << std::endl;
	_type = source._type;
	return *this;
}

Dog::~Dog() {
	std::cout << RED << "Dog class Default destructor called!" << NONE << std::endl;
}