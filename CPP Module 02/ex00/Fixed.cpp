/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 14:45:05 by laprieur          #+#    #+#             */
/*   Updated: 2023/08/25 16:51:51 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {
	this->fpnValue = 0;
}

Fixed::Fixed(const Fixed& source) {
	this->fpnValue = source.fpnValue;
}

Fixed& Fixed::operator=(const Fixed& source) {
	if (this != &source)
		this->fpnValue = source.fpnValue;
	return *this;
}

Fixed::~Fixed() {}

int		Fixed::getRawBits(void) const {
	double	fractionalPart, integerPart = 0.0;

	fractionalPart = modf(static_cast<double>(this->fpnValue), &integerPart);
	std::cout << integerPart << std::endl;
	std::cout << fractionalPart << std::endl;
	return 0;
}

/* void	Fixed::setRawBits(int const raw) {
	
} */