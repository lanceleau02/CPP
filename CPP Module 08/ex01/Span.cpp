/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:43:00 by laprieur          #+#    #+#             */
/*   Updated: 2023/10/27 16:04:59 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N) : _numbers(N, 0), _idx(0) {}

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

void			Span::addNumber(int value) {
	if (_idx >= _numbers.size())
		throw std::out_of_range("Index is out of range!");
	_numbers[_idx] = value;
	_idx++;
}

void	Span::addNumbers(int* values, size_t size) {
	if (size + _idx > _numbers.size())
		throw std::out_of_range("Too many elements to add!");
	for (size_t i = 0; i < size; i++)
		addNumber(values[i]);
}

int	Span::shortestSpan() const {
	int					shortestSpan = INT_MAX;
	int					span = 0;
	std::vector<int>	copy(_numbers);
	
	if (_idx < 2)
		throw std::logic_error("Not enough elements in the array!");
	std::sort(copy.begin(), copy.end());
	for (size_t i = 0; i < copy.size() - 1; i++) {
		span = abs(copy[i + 1] - copy[i]);
		if (span < shortestSpan)
			shortestSpan = span;
	}
	return shortestSpan;
}

int	Span::longestSpan() const {
	std::vector<int>	copy(_numbers);
	
	if (_idx < 2)
		throw std::logic_error("Not enough elements in the array!");
	std::sort(copy.begin(), copy.end());
	return (*(copy.end() - 1) - *copy.begin());
}
