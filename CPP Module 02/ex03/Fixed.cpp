/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 14:45:05 by laprieur          #+#    #+#             */
/*   Updated: 2023/09/08 15:11:06 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {
	_rawBits = 0;
}

Fixed::Fixed(const int param) {
	_rawBits = param * (1 << _nbFractionalBits);
}

Fixed::Fixed(const float param) {
	_rawBits = roundf(param * (1 << _nbFractionalBits));
}

Fixed::Fixed(const Fixed& source) {
	*this = source;
}

Fixed& Fixed::operator=(const Fixed& source) {
	_rawBits = source._rawBits;
	return *this;
}

Fixed::~Fixed() {}

bool	Fixed::operator>(const Fixed& source) {
	return (_rawBits > source._rawBits);
}

bool	Fixed::operator<(const Fixed& source) {
	return (_rawBits < source._rawBits);
}

bool	Fixed::operator>=(const Fixed& source) {
	return (_rawBits >= source._rawBits);
}

bool	Fixed::operator<=(const Fixed& source) {
	return (_rawBits <= source._rawBits);
}

bool	Fixed::operator==(const Fixed& source) {
	return (_rawBits == source._rawBits);
}

bool	Fixed::operator!=(const Fixed& source) {
	return (_rawBits != source._rawBits);
}

Fixed	Fixed::operator+(const Fixed& source) {
	return (Fixed(toFloat() + source.toFloat()));
}

Fixed	Fixed::operator-(const Fixed& source) {
	return (Fixed(toFloat() - source.toFloat()));
}

Fixed	Fixed::operator*(const Fixed& source) {
	return (Fixed(toFloat() * source.toFloat()));
}

Fixed	Fixed::operator/(const Fixed& source) {
	return (Fixed(toFloat() / source.toFloat()));
}

Fixed&	Fixed::operator++(void) {
	++_rawBits;
	return *this;
}

Fixed	Fixed::operator++(int) {
	Fixed	tmp(*this);
	
	++_rawBits;
	return tmp;
}

Fixed&	Fixed::operator--(void) {
	--_rawBits;
	return *this;
}

Fixed	Fixed::operator--(int) {
	Fixed	tmp(*this);
	
	--_rawBits;
	return tmp;
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