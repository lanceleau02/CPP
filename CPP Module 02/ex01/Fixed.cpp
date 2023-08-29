/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 14:45:05 by laprieur          #+#    #+#             */
/*   Updated: 2023/08/29 13:51:40 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	this->_rawBits = 0;
}

Fixed::Fixed(const int param) {
	std::cout << "Int constructor called" << std::endl;
	this->_rawBits = param * (1 << _nbFractionalBits);
}

Fixed::Fixed(const float param) {
	std::cout << "Float constructor called" << std::endl;
	this->_rawBits = roundf(param * (1 << _nbFractionalBits));
}

Fixed::Fixed(const Fixed& source) {
	std::cout << "Copy constructor called" << std::endl;
	*this = source;
}

Fixed& Fixed::operator=(const Fixed& source) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->_rawBits = source._rawBits;
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const {
	return this->_rawBits;
}

int	Fixed::toInt(void) const {
	return this->_rawBits / (1 << _nbFractionalBits);
}

float	Fixed::toFloat(void) const {
	return static_cast<float>(this->_rawBits) / (1 << _nbFractionalBits);
}

void	Fixed::setRawBits(int const raw) {
	this->_rawBits = raw;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fp) {
	os << fp.toFloat();
	return os;
}