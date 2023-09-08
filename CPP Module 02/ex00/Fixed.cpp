/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 14:45:05 by laprieur          #+#    #+#             */
/*   Updated: 2023/09/08 13:00:39 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	_rawBits = 0;
}

Fixed::Fixed(const Fixed& source) {
	std::cout << "Copy constructor called" << std::endl;
	*this = source;
}

Fixed& Fixed::operator=(const Fixed& source) {
	std::cout << "Copy assignment operator called" << std::endl;
	_rawBits = source.getRawBits();
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return _rawBits;
}

void	Fixed::setRawBits(int const raw) {
	_rawBits = raw;
}
