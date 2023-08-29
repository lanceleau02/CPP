/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 14:45:05 by laprieur          #+#    #+#             */
/*   Updated: 2023/08/29 17:34:38 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {
	this->_rawBits = 0;
}

Fixed::Fixed(const int param) {
	this->_rawBits = param * (1 << _nbFractionalBits);
}

Fixed::Fixed(const float param) {
	this->_rawBits = roundf(param * (1 << _nbFractionalBits));
}

Fixed::Fixed(const Fixed& source) {
	*this = source;
}

Fixed& Fixed::operator=(const Fixed& source) {
	if (*this != source)
		this->_rawBits = source._rawBits;
	return *this;
}

bool	Fixed::operator>(const Fixed& source) {
	return (this->_rawBits > source._rawBits);
}

bool	Fixed::operator<(const Fixed& source) {
	return (this->_rawBits < source._rawBits);
}

bool	Fixed::operator>=(const Fixed& source) {
	return (this->_rawBits >= source._rawBits);
}

bool	Fixed::operator<=(const Fixed& source) {
	return (this->_rawBits <= source._rawBits);
}

bool	Fixed::operator==(const Fixed& source) {
	return (this->_rawBits == source._rawBits);
}

bool	Fixed::operator!=(const Fixed& source) {
	return (this->_rawBits != source._rawBits);
}

Fixed	Fixed::operator+(const Fixed& source) {
	return (Fixed(this->toFloat() + source.toFloat()));
}

Fixed	Fixed::operator-(const Fixed& source) {
	return (Fixed(this->toFloat() - source.toFloat()));
}

Fixed	Fixed::operator*(const Fixed& source) {
	return (Fixed(this->toFloat() * source.toFloat()));
}

Fixed	Fixed::operator/(const Fixed& source) {
	return (Fixed(this->toFloat() / source.toFloat()));
}

Fixed&	Fixed::operator++(void) {
	++this->_rawBits;
	return *this;
}

Fixed	Fixed::operator++(int) {
	Fixed	tmp(*this);
	
	++this->_rawBits;
	return tmp;
}

Fixed&	Fixed::operator--(void) {
	--this->_rawBits;
	return *this;
}

Fixed	Fixed::operator--(int) {
	Fixed	tmp(*this);
	
	--this->_rawBits;
	return tmp;
}

Fixed::~Fixed() {}

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

Fixed&	Fixed::min(Fixed& f1, Fixed& f2) {
	return (f1._rawBits > f2._rawBits) ? f2 : f1;
}

const Fixed&	Fixed::min(const Fixed& f1, const Fixed& f2) {
	return (f1._rawBits > f2._rawBits) ? f2 : f1;
}

Fixed&	Fixed::max(Fixed& f1, Fixed& f2) {
	return (f1._rawBits > f2._rawBits) ? f1 : f2;
}

const Fixed&	Fixed::max(const Fixed& f1, const Fixed& f2) {
	return (f1._rawBits > f2._rawBits) ? f1 : f2;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fp) {
	os << fp.toFloat();
	return os;
}