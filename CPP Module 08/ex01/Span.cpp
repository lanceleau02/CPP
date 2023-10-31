/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:43:00 by laprieur          #+#    #+#             */
/*   Updated: 2023/10/31 17:12:50 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N) {
	_numbers.reserve(N);
}

Span::Span(const Span& source) {
	*this = source;
}

Span&	Span::operator=(const Span& source) {
	if (this != &source)
		_numbers = source._numbers;
	return *this;
}

Span::~Span() {}

int			Span::getNumber(unsigned int idx) const {
	if (_numbers.size() == 0 || idx >= _numbers.size())
		throw std::out_of_range("Impossible to get the wanted value!");
	return _numbers[idx];
}

void		Span::setNumber(unsigned int idx, int value) {
	if (_numbers.size() == 0 || idx >= _numbers.size())
		throw std::out_of_range("Impossible to set the wanted value!");
	_numbers[idx] = value;
}

void		Span::addNumber(int value) {
	if (_numbers.size() >= _numbers.capacity())
		throw std::length_error("Impossible to add an element!");
	_numbers.push_back(value);
}

void	Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	if ((std::distance(begin, end) + _numbers.size()) > _numbers.capacity())
		throw std::length_error("Too many elements to add!");
	_numbers.insert(_numbers.end(), begin, end);
}

long int	Span::shortestSpan() const {
	long int			shortestSpan = LONG_MAX;
	long int			span = 0;
	std::vector<int>	copy(_numbers);
	
	if (_numbers.size() < 2)
		throw std::logic_error("Not enough elements in the array!");
	std::sort(copy.begin(), copy.end());
	for (size_t i = 0; i < copy.size() - 1; i++) {
		span = std::abs(static_cast<long int>(copy[i + 1]) - static_cast<long int>(copy[i]));
		if (span < shortestSpan)
			shortestSpan = span;
	}
	return shortestSpan;
}

long int	Span::longestSpan() const {
	std::vector<int>	copy(_numbers);
	
	if (_numbers.size() < 2)
		throw std::logic_error("Not enough elements in the array!");
	std::sort(copy.begin(), copy.end());
	return (static_cast<long int>(*(copy.end() - 1)) - static_cast<long int>(*copy.begin()));
}
