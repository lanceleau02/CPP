/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:43:00 by laprieur          #+#    #+#             */
/*   Updated: 2023/10/26 17:01:13 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n) : _numbers(n, 0), _idx(0) {}

Span::Span(const Span& source) {
	*this = source;
}

Span&	Span::operator=(const Span& source) {
	if (this != &source) {
		_numbers = source._numbers;
		_idx = source._idx;
	}
	return *this;
}

Span::~Span() {}

void			Span::addNumber(unsigned int value) {
	if (_idx >= _numbers.size())
		throw std::out_of_range("Index is out of range!");
	_numbers[_idx] = value;
}

unsigned int	Span::shortestSpan() const {
	unsigned int shortestSpan;
	unsigned int span;
	
	if (_numbers.size() < 2)
		throw std::logic_error("Not enough elements in the array!");
}

unsigned int	Span::longestSpan() const {
	if (_numbers.size() < 2)
		throw std::logic_error("Not enough elements in the array!");
}