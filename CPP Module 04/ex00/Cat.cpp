/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:36:43 by laprieur          #+#    #+#             */
/*   Updated: 2023/09/25 11:14:38 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
	std::cout << GREEN << "Cat class Default constructor called!" << NONE << std::endl;
	_type = "Cat";
}

Cat::Cat(const Cat& source) : Animal(source) {
	std::cout << GREEN << "Cat class Copy constructor called!" << NONE << std::endl;
	*this = source;
}

Cat&	Cat::operator=(const Cat& source) {
	std::cout << GREEN << "Cat class Assignment operator called!" << NONE << std::endl;
	_type = source._type;
	return *this;
}

Cat::~Cat() {
	std::cout << RED << "Cat class Default destructor called!" << NONE << std::endl;
}