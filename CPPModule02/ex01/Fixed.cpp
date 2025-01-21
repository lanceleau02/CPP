/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:04:38 by laprieur          #+#    #+#             */
/*   Updated: 2023/09/08 16:09:08 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	_rawBits = 0;
}

Fixed::Fixed(const int param) {
	std::cout << "Int constructor called" << std::endl;
	_rawBits = param * (1 << _nbFractionalBits);
}

Fixed::Fixed(const float param) {
	std::cout << "Float constructor called" << std::endl;
	_rawBits = roundf(param * (1 << _nbFractionalBits));
}

Fixed::Fixed(const Fixed& source) {
	std::cout << "Copy constructor called" << std::endl;
	*this = source;
}

Fixed& Fixed::operator=(const Fixed& source) {
	std::cout << "Copy assignment operator called" << std::endl;
	_rawBits = source._rawBits;
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const {
	return _rawBits;
}

int	Fixed::toInt(void) const {
	return _rawBits / (1 << _nbFractionalBits);
}

float	Fixed::toFloat(void) const {
	return static_cast<float>(_rawBits) / (1 << _nbFractionalBits);
}

void	Fixed::setRawBits(int const raw) {
	_rawBits = raw;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fp) {
	os << fp.toFloat();
	return os;
}
